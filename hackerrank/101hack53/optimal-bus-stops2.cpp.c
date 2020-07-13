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

#define MX 50005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

ll pos[MX];
ll sum[MX];
ll sum2[MX];

double Cost(int i, int j, double x)
{
    double cost = x*x*(j-i+1.0)-2.0*(sum[j]-sum[i-1])*x+sum2[j]-sum2[i-1];
    return cost;
}

double optimal_Cost(int i, int j)
{
    double l = pos[i], r = pos[j];
    for(int i = 0; i < 100; i++)
    {
        double a = (l*2.0+r)/3;
        double b = (l+2.0*r)/3;
        if(Cost(a)<Cost(b))
        {
            r = b;
        }else{
            l = a;
        }
    }
    return Cost(l);
}

double dp[105][MX];


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1;  i <= n; i++)
    {
        scanf("%lld", &pos[i]);
        sum[i] = pos[i];
        sum[i] += sum[i-1];

        sum2[i] = pos[i]*pos[i];
        sum2[i] += sum2[i-1];
    }
    if(n<=k)
    {
        printf("%.10f\n", 0.0);
        return 0;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[1][i] = optimal_Cost(1,i);
        //printf("%d %f\n", i, dp[1][i]);
    }
    for(int i = 2; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = mod*mod;
            for(int k = 1; k <= j; k++)
            {
                dp[i][j] = min(dp[i][j],dp[i-1][k-1]+optimal_Cost(k,j));
            }
        }
    }
//    for(int i = 1; i <= k; i++, puts(""))
//        for(int j = 1; j <= n; j++)
//            printf("%f ", dp[i][j]);
    printf("%.10f\n", dp[k][n]);
    return 0;
}

