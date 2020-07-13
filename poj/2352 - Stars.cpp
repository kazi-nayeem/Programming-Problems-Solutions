#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MX 100050

const int m = 32005;

int tree[MX*3], lazy[MX*3];
int res[MX];

void update(int node, int beg, int en, int i, int j, int val);
int query(int node, int beg, int en, int i, int j);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x, y;


    while(scanf("%d", &n) == 1)
    {
        memset(tree, 0, sizeof tree);
        memset(lazy, -1, sizeof lazy);
        memset(res, 0, sizeof res);

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            res[query(1,0,m,0,x)]++;
            update(1,0,m,x,x,1);
        }
        for(int i = 0; i < n; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}

void update(int node, int beg, int en, int i, int j, int val)
{
    if(beg > j || en < i) return;
    if(beg == en)
    {
        tree[node] += val;
        lazy[node] = -1;
        return;
    }
    if(beg >= i && en <= j)
    {
        tree[node] +=  val * (en-beg+1);
        lazy[node] +=  val;
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

