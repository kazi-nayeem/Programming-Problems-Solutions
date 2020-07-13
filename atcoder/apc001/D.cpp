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
#include<complex>
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

#define MX 100005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

struct data
{
    int u, cost;
    data() {}
    data(int u, int cost): u(u), cost(cost) {}
    bool operator < (const data & p) const
    {
        return cost>p.cost;
    }
};

struct quueue
{
    priority_queue<data> qu;
    quueue() {}
    quueue(priority_queue<data> qu): qu(qu) {}
    bool operator < (const quueue & p) const
    {
        if(qu.empty())
            return true;
        if(p.qu.empty())
            return false;
        return qu.top().cost>p.qu.top().cost;
    }
};

priority_queue<data> qu2;
vector<int> adj[MX];
int arr[MX];
int flag[MX];

void dfs(int u)
{
    if(flag[u])
        return ;
    flag[u] = 1;
    qu2.push(data(u,arr[u]));
    for(int i = 0; i < adj[u].size(); i++)
        dfs(adj[u][i]);
    return ;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<quueue> fin;

    for(int i = 0; i < n; i++)
    {
        if(flag[i])
            continue;
        while(!qu2.empty())
            qu2.pop();
        dfs(i);

        fin.push(quueue(qu2));

        while(!qu2.empty())
            qu2.pop();
    }
    ll res = 0;
    while(fin.size() > 1)
    {
        quueue one = fin.top();
        fin.pop();

        quueue two = fin.top();
        fin.pop();

        if(one.qu.empty() || two.qu.empty())
        {
            res = -1;
            break;
        }
        res += one.qu.top().cost;
        res += two.qu.top().cost;
        one.qu.pop();
        two.qu.pop();
        while(!two.qu.empty())
        {
            one.qu.push(two.qu.top());
            two.qu.pop();
        }
        fin.push(one);
    }
    if(res == -1)
        puts("Impossible");
    else
        printf("%lld\n", res);
    return 0;
}

