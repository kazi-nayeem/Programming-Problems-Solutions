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

#define MX 100505
#define inf 100000000

const ll mod = 1000000007ll;

struct Matrix
{
    ll arr[2][2];
    Matrix()
    {
        memset(arr,0,sizeof arr);
    }
    Matrix operator + (const Matrix & p) const
    {
        Matrix res;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            {
                res.arr[i][j] = (arr[i][j]+p.arr[i][j])%mod;
            }
        return res;
    }
    Matrix operator * (const Matrix & p) const
    {
        Matrix res;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            {
                res.arr[i][j] = 0;
                for(int k = 0; k < 2; k++)
                    res.arr[i][j] += (arr[i][k]*p.arr[k][j])%mod;
                res.arr[i][j] %= mod;
            }
        return res;
    }
    void unit()
    {
        memset(arr,0,sizeof arr);
        for(int i = 0; i < 2; i++)
            arr[i][i] = 1;
    }
    void print_mat()
    {
        puts("------------");
        for(int i = 0; i < 2; i++, puts(""))
            for(int j = 0; j < 2; j++)
                printf("%lld ", arr[i][j]);
        puts("------------");
    }
};

Matrix pre[MX];

void init()
{
    pre[0].unit();
    Matrix mat;
    mat.arr[0][0] = 1;
    mat.arr[0][1] = 1;
    mat.arr[1][0] = 1;
    for(int i = 1; i < MX; i++)
    {
        pre[i] = pre[i-1]*mat;
    }
}

vector<int> adj[2*MX];
ll dp[2*MX];
int arr[2*MX];
Matrix child[2*MX];

Matrix dfs(int u, int p)
{
    printf("%d\n", u);
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        Matrix now = dfs(v,u);
        Matrix res = now*pre[arr[u]];
        dp[u] += res.arr[0][0];
        res = res*child[u];
        dp[u] += res.arr[0][0];
        dp[u] %= mod;
        child[u] = child[u]+now;
    }
    child[u] = child[u]*pre[arr[u]];
    child[u] = child[u]+pre[arr[u]];
    //printf("node child %d\n", u);
    //child.print_mat();
    //printf("%d\n", u);
    return child[u];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();

    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dfs(1,1);
    //puts("ok");
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += dp[i]*2;
        //printf("%lld\n", dp[i]);
        ans += pre[arr[i]].arr[0][0];
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}


