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

pii pos[MX];
int cost[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            pos[x] = make_pair(i,j);
        }
    for(int i = 1; i <= n*m; i++)
    {
        if(i<=d) continue;
        cost[i] = cost[i-d]+abs(pos[i].first-pos[i-d].first)+abs(pos[i].second-pos[i-d].second);
    }
    int q, l, r;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", cost[r]-cost[l]);
    }
    return 0;
}

