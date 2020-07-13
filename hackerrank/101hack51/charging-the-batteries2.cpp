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

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int n, m, k;
vector<int> adj[4];
vector<pii> arr;

int up(int k)
{
    int cost = 0;
    int pos = upper_bound(adj[0].begin(), adj[0].end(),0)-adj[0].begin();
    k -= pos;
    if(k <= 0) return 0;
    if(adj[2].size()>=k)
    {
        return adj[2][k-1];
    }
    cost += n;
    k -= adj[2].size();
    if(adj[1].size()>=k)
    {
        cost += adj[1][k-1];
        return cost;
    }
    cost += n;
    k -= adj[1].size();
    if(adj[3].size()>=k)
    {
        cost += n - adj[3][adj[3].size()-k];
        return cost;
    }
    cost += n;
    k -= adj[3].size();
    cost += n-adj[0][adj[0].size()-k];
    return cost;
}

int rig(int k)
{
    int cost = 0;
    if(adj[0].size()>=k)
    {
        cost += adj[0][k-1];
        return cost;
    }
    cost += n;
    k -= adj[0].size();
    if(adj[3].size()>=k)
    {
        cost += adj[3][k-1];
        return cost;
    }
    cost += n;
    k -= adj[3].size();
    if(adj[1].size()>=k)
    {
        cost += n-adj[1][adj[1].size()-k];
        return cost;
    }
    cost += n;
    k -= adj[1].size();
    cost += n-adj[2][adj[2].size()-k];
    return cost;
}

int cost(pii a, pii b)
{
    if(a.first == b.first || a.second == b.second)
    {
        return abs(a.first-b.first)+abs(a.second-b.second);
    }
    if((a.first == 0 || a.first == n) && (b.second == 0 || b.second == n))
        return abs(a.first-b.first)+abs(a.second-b.second);
    if((a.second == 0 || a.second == n) && (b.first == 0 || b.first == n))
        return abs(a.first-b.first)+abs(a.second-b.second);

}

pii add(pii a)
{
    if(a.first == 0 && a.second<n)
    {
        return {0,a.second+1};
    }
    if(a.first == n && a.second>0)
    {
        return {n,a.second-1};
    }
    if(a.second == 0 && a.first>0)
    {
        return {a.first-1,0};
    }
    if(a.second == n && a.first<n)
    {
        return {a.first+1,0};
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x, y;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        if(y == 0)
            adj[0].push_back(x);
        else if(y == n)
            adj[1].push_back(x);
        else if(x == 0)
            adj[2].push_back(y);
        else
            adj[3].push_back(y);
    }
    for(int i = 0; i < 4; i++)
        sort(adj[i].begin(), adj[i].end());
    for(int i = 0; i < adj[0].size(); i++)
    {
        arr.push_back({adj[0][i],0});
    }
    for(int i = 0; i < adj[3].size(); i++)
    {
        arr.push_back({n,adj[3][i]});
    }
    for(int i = adj[1].size()-1; i >= 0; i--)
    {
        arr.push_back({adj[1][i],n});
    }
    for(int i = adj[2].size()-1; i >= 0; i--)
    {
        arr.push_back({0,adj[2][i]});
    }
    //printf("%d\n", up(k));
    //printf("%d\n", rig(k));
    int total = 0;
    int ans = 4*n+10;
    for(int i = 1; i+1 < k; i++)
    {
        total += cost(arr[i],arr[i-1]);
    }
    printf("%d\n", min(up(k), rig(k)));
    return 0;
}

