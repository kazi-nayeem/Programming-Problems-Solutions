#include<cstdio>
#include<cstring>
using namespace std;

#define MX 100050
#define ll long long int

struct data
{
    ll sum;
    int add;
};

data tree[MX*3];

ll query(int node, int b, int e, int i, int j);
void update(int node, int b, int e, int i, int j, int val);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, q, n, t, x, y, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        memset(tree, -1, sizeof tree);
        scanf("%d%d", &n, &q);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &t, &x, &y);
            if(t == 2)
                printf("%lld\n", query(1,1,n,x+1,y+1));
            else
            {
                scanf("%d", &v);
                update(1,1,n,x+1,y+1,v);
            }
        }
    }
    return 0;
}

ll query(int node, int b, int e, int i, int j)
{
    if(e < i || b > j) return 0;
    if(i<=b && j >= e)
        return tree[node].sum;
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    if(tree[node].add != -1)
    {
        update(left, b, mid, b, e, tree[node].add);
        update(right, mid+1, e, b, e, tree[node].add);
        tree[node].add = -1;
    }
    ll su1 = query(left, b, mid, i, j);
    ll su2 = query(right, mid+1, e, i, j);
    return su1+su2;
}
void update(int node, int b, int e, int i, int j, int val)
{
    if(e < i || b > j) return;
    if(b == e)
    {
        tree[node].sum = val;
        tree[node].add = -1;
        return;
    }
    if(i<=b && j >= e)
    {
        tree[node].sum = (ll) val * (e-b+1);
        tree[node].add = val;
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    if(tree[node].add != -1)
    {
        update(left, b, mid, b, e, tree[node].add);
        update(right, mid+1, e, b, e, tree[node].add);
        tree[node].add = -1;
        //tree[node].sum = tree[left].sum+tree[right].sum;
    }
    update(left, b, mid, i, j, val);
    update(right, mid+1, e, i, j, val);
    tree[node].sum = tree[left].sum+tree[right].sum;
    return;
}

