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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll dp[1<<18][100];
int len, mod;
char str[100];

ll func(int mask, int m, int tk)
{
    dp[(1<<len)-1][0] = 1;
    for(mask = (1<<len)-2; mask>=0; mask--)
    {
        tk = __builtin_popcount(mask);
        for(m = 0; m < mod; m++)
            for(int i = 0; i < len; i++)
            {
                if(((mask>>i)&1) == 1) continue;
                if(str[i] == '0' && tk == 0) continue;
                if(i > 0 && str[i] == str[i-1] && (((mask>>(i-1))&1) == 0)) continue;
                dp[mask][m] += dp[mask | (1<<i)][(m*10+str[i]-'0')%mod];
            }
    }
    return dp[0][0];
}

int main()
{
    scanf("%s %d", str, &mod);
    len = strlen(str);
    //memset(dp,-1,sizeof dp);
    sort(str,str+len);
    printf("%I64d\n", func(0,0,0));
    return 0;
}
