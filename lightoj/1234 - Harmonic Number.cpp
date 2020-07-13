#include<stdio.h>
using namespace std;

#define MX 100000002

double dp[1000005];

int main()
{
    double ans = 0;
    for(int i = 1; i < MX; i++)
    {
        ans += (double) 1.0/i;
        if((i % 100) == 0)
            dp[i/100] = ans;
    }
    int te = 1, ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        ans = dp[n/100];
        for(int i = ((n/100)*100)+1; i <= n; i++)
            ans += (double)1.0/i;
        printf("Case %d: %.10lf\n", te++, ans);
    }
    return 0;
}
