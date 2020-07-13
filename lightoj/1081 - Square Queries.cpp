#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 505

int arr[MX][MX];
int tree[MX][MX*4];

void init(int row, int node, int b, int e);
int query(int row, int node, int b, int e, int i, int j);

int main()
{
    int te, ti, n, q, u, v, s;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &arr[i][j]);
        for(int i = 1; i <= n; i++)
            init(i,1,1,n);
        printf("Case %d:\n", te);
        int res;
        for(int i = 0; i < q; i++)
        {
            res = 0;
            scanf("%d%d%d", &u, &v, &s);
            for(int i = u; i < u+s; i++)
                res = max(res,query(i,1,1,n,v,v+s-1));
            printf("%d\n", res);
        }
    }
    return 0;
}


void init(int row, int node, int b, int e)
{
    if(b == e)
    {
        tree[row][node] = arr[row][b];
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    init(row,left,b,mid);
    init(row,right,mid+1,e);
    tree[row][node] = max(tree[row][left],tree[row][right]);
    return;
}
int query(int row, int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[row][node];
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    return max(query(row,left,b,mid,i,j), query(row,right,mid+1,e,i,j));
}

