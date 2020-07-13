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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll ncr[400][400];

ll NCR(int n, int r)
{
    if(n == r || r == 0) return 1;
    if(n<r) return 0;
    ll &res = ncr[n][r];
    if(res != -1) return res;
    res = NCR(n-1,r)+NCR(n-1,r-1);
    res%=mod;
    return res;
}

ll mov[105][105][105];

ll movFunc(int mx, int pos, int m)
{
    if(m == 0) return 1;
    ll &res = mov[mx][pos][m];
    if(res != -1) return res;
    res = 0;
    if(pos>1)
        res = movFunc(mx,pos-1,m-1);
    if(pos<mx)
        res += movFunc(mx,pos+1,m-1);
    res %= mod;
    return res;
}

ll dp[11][305];
int dim[100];
int init[100];

ll func(int pos, int m)
{
    if(pos == 0)
    {
        if(m == 0) return 1;
        return 0;
    }
    ll &res = dp[pos][m];
    if(res != -1) return res;
    res = 0;
    for(int i = 0; i <= m; i++)
    {
        res += (((NCR(m,i)*func(pos-1,m-i))%mod)*movFunc(dim[pos],init[pos],i))%mod;
        res%=mod;
    }
    res %= mod;
    return res;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(ncr,-1,sizeof ncr);
    memset(mov,-1,sizeof mov);
    /*for(int i = 0;i<10; i++)
    {
        for(int j = 0; j <= 10; j++)
            printf("%lld ", NCR(i,j));
        puts("");
    }*/
    //for(int i = 1; i <= 5; i++)
      //  printf("%lld ", movFunc(5,i,1));
    //puts("");
    int te, ti, n, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &init[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &dim[i]);
        }
        printf("%lld\n", func(n,m));
    }
    return 0;
}


