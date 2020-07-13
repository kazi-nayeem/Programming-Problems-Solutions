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

#define MX 10000005
#define inf 100000000


inline int mod(int i, int m)
{
    return ((i%m)+m)%m;
}

int mov[MX];
int dist[3*MX];
queue<int> qu;
int n;

inline int getmov(int i)
{
    return mov[mod(i,n)];
}

int getval(int i)
{
    return dist[i+MX];
}

void setval(int i, int v)
{
    dist[i+MX] = v;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int s, t;
    scanf("%d %d %d", &n, &s, &t);
    ll g, seed, p;
    scanf("%d %lld %lld %lld", &mov[0], &g, &seed, &p);
    for(int i = 1; i < n; i++)
        mov[i] = (mov[i-1]*g+seed)%p;
    memset(dist,-1,sizeof dist);
    qu.push(s);
    setval(s,0);
    int low = s, hi = s;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        if(mod(u,n) == t)
        {
            printf("%d\n", getval(u));
            return 0;
        }
        int mo = getmov(u);
        while(((low-1)>= (u-mo)) && ((low+MX) > 0))
        {
            low--;
            setval(low,getval(u)+1);
            qu.push(low);
        }
        while(((hi+1)<= (u+mo)) && ((hi+MX) < (3*MX)))
        {
            hi++;
            setval(hi,getval(u)+1);
            qu.push(hi);
        }
    }
    printf("-1\n");
    return 0;
}


