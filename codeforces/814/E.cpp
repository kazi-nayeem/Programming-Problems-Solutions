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

#define MX 25
#define inf 100000000

const ll mod = 1000000007ll;

ll ncr[100][5];

void ncrfun()
{
    for(int i = 0; i < 100; i++)
        ncr[i][0] = 1;
    for(int i = 1; i < 100; i++)
        for(int j = 1; j < 5; j++)
            ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j-1])%mod;
}

ll dp[MX][MX][MX][MX][MX];
int arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int p1 = 0, p2 = 0, c1 = 0, c2 = 0;
    if(arr[1] == 2) p1 = 1;
    else p2++;
    if(arr[2] == 2) c1 = 1;
    else c2++;
    dp[2][p1][p2][c1][c2] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(p1 = 0; p1 <= i; p1++)
            for(p2 = 0; p2+p1<=i; p2++)
                for(c1 = 0; c1+p2+p1<=i; c1++)
                    for(c2 = 0; c2+c1+p2+p1<=i; c2++)
                    {

                    }
    }
    return 0;
}

