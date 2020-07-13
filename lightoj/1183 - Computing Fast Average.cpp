#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MX 100050
#define ll int

int tree[MX*3], lazy[MX*3];

void update(int node, int beg, int en, int i, int j, int val);
int query(int node, int beg, int en, int i, int j);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, n, q, x, y, t, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        n--;
        memset(tree, 0, sizeof tree);
        memset(lazy, -1, sizeof lazy);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &t, &x, &y);
            if(t == 1)
            {
                scanf("%d", &v);
                update(1,0,n,x,y,v);
            }
            else
            {
                int sum = query(1,0,n,x,y);
                int el = (ll) y-x+1;
                int gc = __gcd(sum,el);
                sum /= gc;
                el /= gc;
                if(el == 1)
                    printf("%d\n", sum);
                else
                    printf("%d/%d\n", sum, el);
            }
        }
    }
    return 0;
}

void update(int node, int beg, int en, int i, int j, int val)
{
    if(beg > j || en < i) return;
    if(beg == en)
    {
        tree[node] = val;
        lazy[node] = -1;
        return;
    }
    if(beg >= i && en <= j)
    {
        tree[node] =  val * (en-beg+1);
        lazy[node] =  val;
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (beg+en)/2;
    if(lazy[node] != -1)
    {
        update(left,beg, mid, beg, en, lazy[node]);
        update(right, mid+1, en, beg, en, lazy[node]);
        lazy[node] = -1;
    }
    update(left,beg, mid, i, j, val);
    update(right, mid+1, en, i, j, val);
    tree[node] = tree[left]+tree[right];
    return;
}
int query(int node, int beg, int en, int i, int j)
{
    if(beg > j || en < i) return 0;
    if(beg >= i && en <= j)
        return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (beg+en)/2;
    if(lazy[node] != -1)
    {
        update(left,beg, mid, beg, en, lazy[node]);
        update(right, mid+1, en, beg, en, lazy[node]);
        lazy[node] = -1;
        tree[node] = tree[left]+tree[right];
    }
    int s1 = query(left,beg, mid, i, j);
    int s2 = query(right, mid+1, en, i, j);
    return s1+s2;
}
