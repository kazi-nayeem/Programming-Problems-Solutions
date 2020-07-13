//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define mlr int mid = (beg+fini)>>1;\
            int left = node << 1;\
            int right = left+1;

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int tree[MX*4];

void update(int node, int beg, int fini, int pos, int val)
{
    if(beg == fini)
    {
        tree[node] = val;
        return;
    }

    mlr;

    if(pos <= mid) update(left,beg,mid, pos, val);
    else update(right,mid+1,fini, pos, val);

    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node, int beg, int fini, int pos)
{
    if(beg == fini)
    {
        return tree[node];
    }
    mlr;
    int p1 = 0, p2 = 0;
    if(mid >= pos)
        p1 = query(left,beg,mid, pos);
    else
        p1 = query(right,mid+1,fini, pos);
    return p1;
}

vector<int> adj[MX];
vector<int> arr[MX];
int res[MX];

void dfs(int u, int p)
{
    for(int i = 0; i < arr[u].size(); i++)
    {
        int v = arr[u][i];
        int qu = query(1,1,MX,abs(v));
        if(v>0)
        {
            if(qu == 0)
            {
                update(1,1,MX,abs(v),1);
            }
            else
            {
                arr[u][i] = 0;
            }
        }
        else
        {
            if(qu == 1)
            {
                update(1,1,MX,abs(v),0);
            }
            else
            {
                arr[u][i] = 0;
            }
        }
    }
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,u);
    }
    res[u] = tree[1];
    for(int i = 0; i < arr[u].size(); i++)
    {
        int v = arr[u][i];
        if(v<0)
        {
            update(1,1,MX,abs(v),1);
        }
        else if(v>0)
        {
            update(1,1,MX,abs(v),0);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        int k, x;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++)
        {
            scanf("%d", &x);
            arr[i].push_back(x);
        }
    }
    //puts("---");
    dfs(1,1);
    for(int i = 1; i <= n; i++)
        printf("%d\n", res[i]);
    return 0;
}

