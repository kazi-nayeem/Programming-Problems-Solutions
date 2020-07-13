#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

#define MX 100050

double dp[MX];

int main()
{
    dp[0] = 0.0;
    for(int i = 1; i < MX; i++)
        dp[i] = (double) dp[i-1]+(double)(1.0/i);
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        printf("Case %d: %.8lf\n", te, n*dp[n]);
    }
    return 0;
}
