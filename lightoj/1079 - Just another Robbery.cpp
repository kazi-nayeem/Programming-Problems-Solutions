#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;

#define MX 10005

double dp[MX];
double prob[105];
int arr[105];


int main()
{
    int te = 1, ti, n;
    double pr;
    int total;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%lf%d", &pr, &n);
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %lf", &arr[i], &prob[i]);
            total += arr[i];
        }
        for(int i = 0; i <= total; i++)
            dp[i] = 1000.0;
        dp[0] = 0.0;
        total = 0;
        for(int i = 0; i < n; i++)
        {
            total += arr[i];
            for(int j = total; j >= arr[i]; j--)
            {
                if(dp[j-arr[i]] >= pr) continue;
                double ans = dp[j-arr[i]];
                ans += (double)(1.0 - ans)*prob[i];
                dp[j] = min(dp[j],ans);
            }
        }
        for(int j = total; j >= 0; j--)
            if(dp[j] <= pr)
            {
                printf("Case %d: %d\n", te++, j);
                break;
            }
    }
    return 0;
}
