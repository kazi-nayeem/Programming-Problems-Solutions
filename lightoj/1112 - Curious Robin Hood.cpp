#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100005
#define ll long long

int arr[MX];
ll tree[MX*3];

void init(int node,int b, int e);
void update(int node, int b, int e, int i, int newvalue);
ll query(int node, int b, int e, int i, int j);

int main()
{
    int te, ti, n, q, t, u, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", arr+i);
        init(1,1,n);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &t);
            if(t == 1)
            {
                scanf("%d", &u);
                u++;
                printf("%d\n", arr[u]);
                arr[u] = 0;
                update(1,1,n,u,0);
            }
            else if(t == 2)
            {
                scanf("%d%d", &u, &v);
                u++;
                //printf("add %d\n", arr[u]);
                arr[u] += v;
                update(1,1,n,u,arr[u]);
                //init(1,1,n);
            }
            else
            {
                scanf("%d%d", &u, &v);
                u++, v++;
                printf("%lld\n", query(1,1,n,u,v));
            }
        }
    }
    return 0;
}

void init(int node,int b, int e)
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
    tree[node] = tree[left]+tree[right];
    return;
}

void update(int node, int b, int e, int i, int newvalue)
{
    //printf("ok");
    if(i < b || i > e) return;
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node] = tree[left]+tree[right];
    return;
}

ll query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node];
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
}
