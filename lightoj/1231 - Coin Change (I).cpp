#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 1002
#define MX 51

int dp[MAX][MX];
int coin[MX];
int tak[MX];
int co;

int coinchange(int i, int n);

int main()
{
    int i, n;
    int ti, te;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &co, &n);

        for(i = 0;i < co;i++)
            scanf("%d", &coin[i]);
        for(i = 0; i < co; i++)
            scanf("%d", &tak[i]);

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %d\n", te, coinchange(0,n));
    }
    return 0;
}

int coinchange(int i, int n)
{
    if(i >= co)
    {
        if(n == 0) return 1;
        return 0;
    }
    if(dp[n][i] != -1) return dp[n][i];
    int ret = 0;
    for(int j = 0; j <= tak[i] && j*coin[i] <= n; j++)
        ret = (ret+coinchange(i+1,n - j*coin[i])) % 100000007;
    return dp[n][i] = ret;
}
