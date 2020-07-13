#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

#define MX 1429500
#define mlr int mid = (beg+fini)>>1;\
            int left = node << 1;\
            int right = left+1;

int tree[MX*2];

void init(int node, int beg, int fini);
void update(int node, int beg, int fini, int pos);
int query(int node, int beg, int fini, int pos);

int main()
{
    //freopen("input.txt", "r", stdin);
    init(1, 1,MX/2);
    for(int i = 2; i < 100000; i++)
    {
        int k = query(1,1,MX/2,i);
        for(int j = k; j <= tree[1]; j+=k-1)
            update(1,1,MX/2,j);
    }

    int te, ti, n, q, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", te, query(1,1,MX/2,n));

    }
    return 0;
}

void init(int node, int beg, int fini)
{
    if(beg == fini)
    {
        tree[node] = 1;
        return;
    }

    mlr;

    init(left,beg,mid);
    init(right,mid+1,fini);

    tree[node]=tree[left]+tree[right];
    return;
}

void update(int node, int beg, int fini, int pos)
{
    if(beg == fini)
    {
        tree[node] = 0;
        return;
    }

    mlr;

    if(pos <= tree[left]) update(left,beg,mid, pos);
    else update(right,mid+1,fini, pos-tree[left]);

    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node, int beg, int fini, int pos)
{
    if(beg == fini)
        return beg*2-1;
    mlr;
    int p1 = 0, p2 = 0;
    if(tree[left] >= pos)
        p1 = query(left,beg,mid, pos);
    else
        p1 = query(right,mid+1,fini, pos-tree[left]);
    return p1;
}
