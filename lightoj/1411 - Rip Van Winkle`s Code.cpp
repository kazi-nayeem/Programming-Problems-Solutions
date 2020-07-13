#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

#define ll long long int
#define MX 250050
#define MX2 250010
#define INF 2000000

struct data
{
    ll sum;
    int x, start, dif;
};

data total_sum(data a, data b)
{
    data tem;
    tem.sum = a.sum+b.sum;
    tem.x = INF;
    tem.start = 0;
    tem.dif = 0;
}

data tree[MX*4];

void _replace(int node, int beg, int en, int i, int j, int x);
void _update(int node, int beg, int en, int i, int j, int st, int di);
ll _query(int node, int beg, int en, int i, int j);

int main()
{
    int te, ti, n, u, v, x;
    char ch;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        memset(tree,0,sizeof tree);
        for(int i = 0; i <= MX2; i++) tree[i].x = INF;
        for(int i = 0; i < n; i++)
        {
            scanf(" %c %d %d", &ch, &u, &v);
            if(ch == 'S')
            {
                printf("%lld\n", _query(1,1,MX2,u,v));
            }
            else if(ch == 'C')
            {
                scanf("%d", &x);
                _replace(1,1,MX2,u,v,x);
            }
        }
    }
    return 0;
}

void _update(int node, int beg, int en, int i, int j, int st, int di)
{
    return;
}

void _replace(int node, int beg, int en, int i, int j, int x)
{
    if(beg > j || en < i) return;
    if(beg >= i && en <= j)
    {
        tree[node].sum = (ll) (en-beg+1)*x;
        tree[node].start = 0;
        tree[node].dif = 0;
        tree[node].x = x;
        return;
    }

    int mid = (beg+en)/2;
    int left = node*2;
    int right = left+1;

    if(tree[node].x != INF)
    {
        _replace(left,beg,mid,beg,en,tree[node].x);
        _replace(right,mid+1,en,beg,en,tree[node].x);
    }
    if(tree[node].start != 0)
    {
        _update(left,beg,mid,beg,en,tree[node].start,tree[node].dif);
        _update(right,mid+1,en,beg,en,tree[node].start,tree[node].dif);
    }
    _replace(left,beg,mid,i,j,x);
    _replace(right,mid+1,en,i,j,x);
    tree[node] = total_sum(tree[left],tree[right]);
    return;
}

ll _query(int node, int beg, int en, int i, int j)
{
    if(beg > j || en < i) return 0;
    if(beg >= i && en <= j)
        return tree[node].sum;

    int mid = (beg+en)/2;
    int left = node*2;
    int right = left+1;

    if(tree[node].x != INF)
    {
        _replace(left,beg,mid,beg,en,tree[node].x);
        _replace(right,mid+1,en,beg,en,tree[node].x);
    }
    if(tree[node].start != 0)
    {
        _update(left,beg,mid,beg,en,tree[node].start,tree[node].dif);
        _update(right,mid+1,en,beg,en,tree[node].start,tree[node].dif);
    }
    if((tree[node].start != 0) || (tree[node].x != INF))
        tree[node] = total_sum(tree[left],tree[right]);
    ll q1 = _query(left,beg,mid,i,j);
    ll q2 = _query(right,mid+1,en,i,j);
    return q1+q2;
}
