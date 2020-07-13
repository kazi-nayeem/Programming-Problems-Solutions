#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100005

int arr[MX];
int tree[MX*2];

void init(int node, int b, int e);
int query(int node, int b, int e, int i, int j);

int main()
{
    int te, ti, n, q, u, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        init(1,1,n);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", query(1,1,n,u,v));
        }
    }
    return 0;
}


void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = min(tree[left], tree[right]);
    return;
}
int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 105000;
    if(b >= i && e <= j) return tree[node];
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    return min(query(left,b,mid,i,j), query(right,mid+1,e,i,j));
}
