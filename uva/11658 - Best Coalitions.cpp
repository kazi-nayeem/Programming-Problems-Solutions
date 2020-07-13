#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

int dp[10005];
int arr[105];

int main()
{
    int n, m, t1, t2;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0&&m == 0) return 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d.%d", &t1, &t2);
            arr[i] = t1*100+t2;
        }
        if(arr[m] > 5000)
        {
            printf("100.00\n");
            continue;
        }
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(i == m) continue;
            for(int j = 10000; j >= arr[i]; j--)
                if(dp[j] == 0) dp[j] = dp[j-arr[i]];
        }
        for(int i = 5001 - arr[m]; i <= 10000; i++)
            if(dp[i] == 1)
            {
                printf("%.2lf\n",(double) 100*arr[m]/(i+arr[m]));
                break;
            }
    }
    return 0;
}
