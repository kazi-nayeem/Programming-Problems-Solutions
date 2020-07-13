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

char str[600][600];
int dp[600][600];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int row, col;
    scanf("%d %d", &row, &col);
    for(int i = 0; i < row; i++)
        scanf("%s", str[i]);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(j>0) dp[i][j] = dp[i][j-1];
            if(str[i][j] == 'x') dp[i][j]++;
        }

    /*for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", dp[i][j]);
        }
        puts("");
    }*/
    int res = -1;
    for(int i = 0;  i < col; i++)
    {
        for(int j = i+1; j < col; j++)
        {
            int pre = -1;
            for(int k = 0; k < row; k++)
            {
                if(str[k][i] == 'x' || str[k][j] == 'x')
                {
                    pre = -1;
                    continue;
                }
                if(dp[k][i] == dp[k][j])
                {
                    if(pre == -1)
                    {
                        pre = k;
                    }
                    else
                    {
                        res = max(res,2*(j-i)+2*(k-pre));
                    }
                }
            }
        }
    }
    if(res == -1) puts("impossible");
    else printf("%d\n", res);
    return 0;
}


