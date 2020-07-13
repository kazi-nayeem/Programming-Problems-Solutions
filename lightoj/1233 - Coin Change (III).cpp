#include<cstdio>
#include<cstring>
using namespace std;

#define MX 100002
#define MXC 100

int coin[MXC], tak[MXC];
int dp[MX];

int coinchange(const int n, const int co);

int main()
{
    int co, n, ti, te;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &co, &n);
        for(int i = 1; i <= co; i++)
            scanf("%d", coin+i);
        for(int i = 1; i <= co; i++)
            scanf("%d", tak+i);

        printf("Case %d: %d\n", te, coinchange(n,co));
    }
    return 0;
}

int coinchange(const int n, const int co)
{
    memset(dp,-1,sizeof dp);
    dp[0] = 0;
    int total = 0;
    for(int i = 1; i <= co; i++)
    {
        for(int j = coin[i]; j <= n; j++)
        {
            if(dp[j] != -1 || dp[j - coin[i]] == -1) continue;
            if(dp[j - coin[i]] < tak[i])
                dp[j] = dp[j - coin[i]] + 1;
        }
        for(int j = 1; j <= n; j++)
            if(dp[j] != -1)
                dp[j] = 0;
    }
    for(int i = 1; i <= n; i++)
        if(dp[i] != -1) total++;

    return total;
}
