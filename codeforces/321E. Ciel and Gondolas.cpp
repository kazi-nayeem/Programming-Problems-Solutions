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

#define MX 4005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int arr[MX][MX];
int sum[MX][MX];
int cost[MX][MX];

void build(int n) {
    for(int i = 1; i <= n; i++ )
        for(int j = 1; j <= n; j++) {
            sum[i][j] = arr[i][j]+sum[i][j-1];
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            sum[i][j] += sum[i-1][j];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) {
            cost[j][i] = cost[i][j] = sum[j][j]+sum[i-1][i-1]-sum[i-1][j]-sum[j][i-1];
        }
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d ", sum[i][j]);
        puts("");
    }
    puts("-----");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d ", cost[i][j]);
        puts("");
    }*/
}

int dp[MX][MX];

int calc(int divs,int pos, int searchL, int searchR) {
    dp[divs][pos] = inf;
    int ret = searchL;
    for(int i = searchL; i <= searchR; i++) {
        int t = dp[divs-1][i]+cost[i+1][pos];
        if(t<dp[divs][pos]) {
            dp[divs][pos] = t;
            ret = i;
        }
    }
    return ret;
}


void solve(int divs, int L, int R, int searchL, int searchR) {
    if(L>R) return;
    if(L == R) {
        calc(divs,L,searchL, searchR);
        return;
    }
    searchR = min(searchR,R-1);
    if(searchL == searchR) {
        for(int i = L; i <= R; i++)
            calc(divs,i,searchL,searchR);
        return;
    }
    int M = (L+R)/2;
    int optM = calc(divs,M,searchL,searchR);
    solve(divs,L,M-1,searchL,optM);
    solve(divs,M+1,R,optM,searchR);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, d;
    char str[MX*4];
    scanf("%d %d\n", &n, &d);
    for(int i = 1; i <= n; i++){
        gets(str);
        for(int j = 1; j <= n; j++)
            arr[i][j] = str[j*2-2]-'0';
    }

    build(n);
    for(int i = 1; i <= n; i++) {
        dp[1][i] = cost[1][i];
    }
    for(int i = 2; i <= d; i++) {
        solve(i,2,n,i-1,n);
    }
    printf("%d\n", dp[d][n]/2);
    return 0;
}

