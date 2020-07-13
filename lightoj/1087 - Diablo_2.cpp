#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

#define MX 150500
#define mlr int mid = (beg+fini)>>1;\
            int left = node << 1;\
            int right = left+1;

int arr[MX];
int flag[MX];
int tree[MX*4];

void init(int node, int beg, int fini);
void update(int node, int beg, int fini, int pos);
int query(int node, int beg, int fini, int pos);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti, n, q, v;
    char ch;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        printf("Case %d:\n", te);
        memset(flag,0,sizeof flag);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            flag[i] = 1;
        }
        init(1,1,n+q);
        for(int i = 1; i <= q; i++)
        {
            scanf(" %c%d", &ch, &v);
            if(ch == 'a')
            {
                arr[n+i] = v;
                flag[n+i] = 1;
                update(1,1,n+q,n+i);
            }
            else
            {
                if(tree[1] >= v)
                    printf("%d\n", query(1,1,n+q,v));
                else
                    printf("none\n");
            }
        }
    }
    return 0;
}

void init(int node, int beg, int fini)
{
    if(beg == fini)
    {
        tree[node] = flag[beg];
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
        tree[node] = flag[beg];
        return;
    }

    mlr;

    if(pos <= mid) update(left,beg,mid, pos);
    else update(right,mid+1,fini, pos);

    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node, int beg, int fini, int pos)
{
    if(beg == fini)
    {
        flag[beg] = 0;
        tree[node] = 0;
        return arr[beg];
    }
    mlr;
    int p1 = 0, p2 = 0;
    if(tree[left] >= pos)
        p1 = query(left,beg,mid, pos);
    else
        p1 = query(right,mid+1,fini, pos-tree[left]);

    tree[node]=tree[left]+tree[right];
    return p1;
}
