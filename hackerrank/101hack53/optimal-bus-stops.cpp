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

double optimal_Cost(int i, int j)
{
    double x = (double) (sum[j]-sum[i-1])/(j-i+1.0);
    double cost = x*x*(j-i+1.0)-2.0*(sum[j]-sum[i-1])*x+sum2[j]-sum2[i-1];
    return cost;
}

double dp[105][MX];

int calc(int divs,int pos, int searchL, int searchR)
{
    //printf("%d %d %d %d\n", divs,pos,searchL,searchR);
    dp[divs][pos] = mod*mod;
    int ret = searchL;
    for(int i = max(searchL-1,1); i <= min(searchR+1,pos); i++)
    {
        //printf("%d %d %f %f\n", pos, i, dp[divs-1][i-1], optimal_Cost(i,pos));
        double t = dp[divs-1][i-1]+optimal_Cost(i,pos);
        if(t<dp[divs][pos])
        {
            dp[divs][pos] = t;
            ret = i;
            //printf("ok\n");
        }
    }
    //printf(">>>%d %d %f\n", divs, pos, dp[divs][pos]);
    return ret;
}


void solve(int divs, int L, int R, int searchL, int searchR)
{
    if(L>R)
        return;
    if(L == R)
    {
        calc(divs,L,searchL, searchR);
        return;
    }
    searchR = min(searchR,R);
    if(searchL == searchR)
    {
        for(int i = L; i <= R; i++)
            calc(divs,i,searchL,searchR);
        return;
    }
    int M = (L+R)/2;
    int optM = calc(divs,M,searchL,searchR);
    solve(divs,L,M-1,searchL,optM);
    solve(divs,M+1,R,optM,searchR);
}


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
    sort(pos+1,pos+1+n);

    for(int i = 1;  i <= n; i++)
    {
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
        solve(i,1,n,0,n);
    }
//    for(int i = 1; i <= k; i++, puts(""))
//        for(int j = 1; j <= n; j++)
//            printf("%f ", dp[i][j]);
    printf("%.10f\n", dp[k][n]);
    return 0;
}

