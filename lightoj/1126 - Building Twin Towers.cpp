//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cstdlib>

#include<iostream>
using namespace std;

#define MX 500005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[55];
int dp[2][MX/2];

int main()
{
    int ti, n, te;
    scanf("%d", &ti);
    for(te =1; te <= ti; te++)
    {
        scanf("%d", &n);
        int total = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        total /= 2;
        for(int i = 1; i <= total; i++)
            dp[0][i] = -inf;
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            int now = i&1;
            int pre = (1+i)&1;
            for(int j = 0; j <= total; j++)
            {
                //printf("%d %d %d\n", i, j, dp[pre][j]);
                dp[now][j] = dp[pre][j];
                if(j+arr[i]<=total)
                    dp[now][j] = max(dp[pre][j+arr[i]]+arr[i], dp[now][j]);
                if(abs(j-arr[i]) <= total)
                    dp[now][j] = max(dp[pre][abs(j-arr[i])]+arr[i], dp[now][j]);
            }
        }
        if(dp[n&1][0] > 0)
            printf("Case %d: %d\n", te, dp[n&1][0]/2);
        else
            printf("Case %d: impossible\n", te);
    }
    return 0;
}
