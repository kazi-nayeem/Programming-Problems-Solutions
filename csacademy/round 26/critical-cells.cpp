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
#define clrall(name,val) memset(name,(val),sizeof(name))
#define psb(b) push_back((b))

//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define MAXN 100005
#define inf 100000000

const ll mod = 1000000007ll;

struct data{
    int x, y;
    data(){}
    data(int a, int b){
        x = a;
        y = b;
    }
    bool operator < (const data & p) const
    {
        if(x == p.x) return y>p.y;
        return x>p.x;
    }
};

map<int,int> xmp, ymp;

data tree[4*MX];

void init(int n, int b, int e)
{
    if(b == e)
    {
        tree[n].x = -1;
        tree[n].y = -1;
        return;
    }
    int mid = (b+e)/2;
    int l = n*2;
    int r = l+1;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[n] = min(tree[l],tree[r]);
}

void update(int n, int b, int e, int pos, data tem)
{
    if(pos < b || pos > e) return;
    if(b == e && b == pos)
    {
        tree[n] = min(tree[n],tem);
        return;
    }
    int mid = (b+e)/2;
    int l = n*2;
    int r = l+1;
    update(l,b,mid,pos,tem);
    update(r,mid+1,e,pos,tem);
    tree[n] = min(tree[l],tree[r]);
}

data query(int n, int b, int e, int i, int j)
{
    if(j < b || i > e) return data(-1,-1);
    if(i <= b && e <= j)
    {
        return tree[n];
    }
    int mid = (b+e)/2;
    int l = n*2;
    int r = l+1;
    return min(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}

vector<int> adj[MX];
vector<int> point;
int distime[MAXN],height[MAXN],root,col[MAXN],id;

void init(int n)
{
    point.clear();
    for(int i=0;i<=n;i++) adj[i].clear();
    clrall(distime,0);
    clrall(height,0);
    clrall(col,0);
    id=1;
    return ;
}

void dfs_point(int u,int par)
{
    int v,child=0;
    distime[u]=height[u]=id++;
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(v==par) continue;
        if(!distime[v])
        {
            child++;
            dfs_point(v,u);
            height[u]=min(height[u],height[v]);///height update.
            if(distime[u]<=height[v]&&u!=root&&!col[u])
            {
                point.psb(u);///find point.
                col[u]=true;
            }
        }
        else if(distime[u]>distime[v]) height[u]=min(distime[v],height[u]);///back edge.
    }
    if(u==root&&child>=2&&!col[u])
    {
        col[u]=true;
        point.psb(u);///root case.
    }
    return ;
}

data arr[MX];

void func(int u, int l, int r, int ans, int k)
{
    if(l>r) return;
    data tem = query(1,0,k,l,r);

    if(tem.x == ans)
    {
        adj[u].push_back(tem.y);
        adj[tem.y].push_back(u);
        //printf(">>>%d %d\n", u, tem.y);
        func(u,arr[tem.y].y+1,r,ans,k);
        func(u,l,arr[tem.y].y-1,ans,k);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        xmp[arr[i].x] = 0;
        ymp[arr[i].y] = 0;
    }
    xmp[m] = 0;
    ymp[n] = 0;
    arr[k].x = m;
    arr[k].y = n;
    k++;
    xmp[0] = 0;
    ymp[0] = 0;
    arr[k].x = 0;
    arr[k].y = 0;
    k++;
    int cnt = 0;
    for(auto xp = xmp.begin(); xp != xmp.end(); xp++)
    {
        xp->second = cnt++;
    }
    cnt = 0;
    for(auto xp = ymp.begin(); xp != ymp.end(); xp++)
    {
        xp->second = cnt++;
    }
    for(int i = 0; i < k; i++)
    {
        arr[i].x = xmp[arr[i].x];
        arr[i].y = ymp[arr[i].y];
        //printf("%d %d\n", arr[i].x, arr[i].y);
    }
    init(k);
    sort(arr,arr+k);
    init(1,0,k);
    update(1,0,k,arr[0].y,data(0,0));
    for(int i = 1; i < k; i++)
    {
        int ans = query(1,0,k,arr[i].y,arr[0].y).x;
        func(i,arr[i].y,arr[0].y,ans,k);
        update(1,0,k,arr[i].y,data(ans+1,i));
        //printf("%d %d %d\n", arr[i].x, arr[i].y, ans);
    }
    root = 0;
    dfs_point(0,0);
    printf("%d\n", point.size());
    return 0;
}

