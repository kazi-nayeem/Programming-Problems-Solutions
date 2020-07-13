#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100005

struct data{
    int mx, mi;
    data(){}
    data(int a, int b)
    {
        mx = a;
        mi = b;
    }
};

int arr[MX];
data tree[MX*2];

void init(int node, int b, int e);
data query(int node, int b, int e, int i, int j);

int main()
{
    int te, ti, n, dif, res;
    data tem;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &dif);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        init(1,1,n);
        res = 0;
        for(int i = 1, j = dif; j <= n; i++, j++)
        {
            tem = query(1,1,n,i,j);
            if(res < tem.mx-tem.mi)
                res = tem.mx-tem.mi;
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = data(arr[b], arr[b]);
        return;
    }
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = data(max(tree[left].mx, tree[right].mx), min(tree[left].mi, tree[right].mi));
}

data query(int node, int b, int e, int i, int j)
{
    if(j < b || i > e) return data(-1, 1005000);
    if(b >= i && e <= j) return tree[node];
    int left, right, mid;
    left = node*2;
    right = left+1;
    mid = (b+e)/2;
    data p1 = query(left,b,mid,i,j);
    data p2 = query(right,mid+1,e,i,j);
    return data(max(p1.mx,p2.mx), min(p1.mi,p2.mi));
}
