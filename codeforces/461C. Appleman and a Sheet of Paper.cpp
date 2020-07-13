#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100005
#define ll long long

int arr[MX];
ll tree[MX*4];

void init(int node,int b, int e);
void update(int node, int b, int e, int i, int newvalue);
ll query(int node, int b, int e, int i, int j);

int main()
{
    int n, q, t, u, v;

    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++)
        arr[i] = 1;
    init(1,1,n);
    int start = 0, en = n-1;
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d", &u);
            update(1,1,n,u,0);
        }
        else
        {
            scanf("%d%d", &u, &v);
            printf("%lld\n", query(1,1,n,start+u,start+v));
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

void update(int node, int b, int e, int i, int j)
{
    //printf("ok");
    if(j < b || i > e) return;
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    update(left,b,mid,i);
    update(right,mid+1,e,i);
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

