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

struct edge
{
    int u, v, w;
    edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> vc;
int parent[MX];

int find_parent(int n)
{
    if(parent[n] == n)
        return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

int mst(const int cities)
{
    sort(vc.begin(), vc.end());
    for(int i = 0; i <= cities; i++)
        parent[i] = i;
    int roads = vc.size();
    int total = 0;
    int u, v;

    for(int i = 0; i < roads; i++)
    {
        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            total += vc[i].w;
        }
    }
    return total;
}

int cost_fun(int n)
{
    vc.clear();
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            vc.push_back(edge(i,j,i^j));
    return mst(n);
}


int main()
{
    int pre = 0;
    for(int i = 2; i <= 100; i++)
    {
        int now = cost_fun(i);
        printf("%d %d\n", i, now, now-pre);
        pre = now;
    }

    return 0;
}


