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

#define MX 200005
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    int p, pos;
    data(int p, int pos): p(p), pos(pos) {}
    bool operator < (const data & a) const
    {
        return p>a.p;
    }
};

priority_queue<data> adj[10];

int arr1[MX];
int arr2[MX];
int arr3[MX];
int flag[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr2[i]);
        adj[arr2[i]].push(data(arr1[i],i));
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr3[i]);
        adj[arr3[i]].push(data(arr1[i],i));
    }
    int m, x;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &x);
        while(!adj[x].empty() && flag[adj[x].top().pos] == 1) adj[x].pop();
        int ans;
        if(adj[x].empty())
            ans = -1;
        else{
            ans = adj[x].top().p;
            flag[adj[x].top().pos] = 1;
        }
        printf("%d ", ans);
    }
    return 0;
}

