#include<cstdio>
#include<cstring>
using namespace std;

const int mod = 100000007;

int dp[2][15005];

int main()
{
    int n, k, s;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &n, &k, &s);
        memset(dp,0,sizeof dp);
        for(int i = 0; i <= s; i++) dp[0][i] = 1;
        for(int i = 1; i <= n; i++)
        {
            int now = i&1;
            int pre = (i+1)&1;
            //for(int j = 0; j < i; j++) dp[now][j] = 0;
            for(int j = 0; j <= s; j++)
            {
                dp[now][j] = dp[now][j-1];
                dp[now][j] += dp[pre][j-1];
                if(j > k)
                    dp[now][j] -= dp[pre][j-k-1];
                dp[now][j] %= mod;
            }
        }
        printf("Case %d: %d\n", te, (((dp[n&1][s]-dp[n&1][s-1])%mod)+mod)%mod);
    }
    return 0;
}
