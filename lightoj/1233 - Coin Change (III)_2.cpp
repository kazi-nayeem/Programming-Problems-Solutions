#include<cstdio>
#include<cstring>
using namespace std;

#define MX 100002
#define MXC 100

int coin[MXC], tak[MXC];
int dp[MX];
int ok[MX];

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
    for(int i = 0; i <= n; i++)
    {
        ok[i] = -1;
        dp[i] = 0;
    }
    ok[0] = 0;
    int total = 0;
    int k;
    for(int i = 1; i <= co; i++)
    {
        for(int j = coin[i]; j <= n; j++)
        {
            k = j - coin[i];
            if(ok[j] != -1 || ok[k] == -1) continue;
            if(ok[k] == i && dp[k] < tak[i])
            {
                ok[j] = i;
                dp[j] = dp[k] + 1;
                total++;
            }
            else if(ok[k] != i)
            {
                ok[j] = i;
                dp[j] = 1;
                total++;
            }
        }
    }
    return total;
}

