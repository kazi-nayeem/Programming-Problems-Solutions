#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long

bool dp[205];
int arr[100];

int main()
{
    int ti, m, c, t, x;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d%d", &m, &c);
        memset(dp,false,sizeof dp);
        dp[0] = true;
        for(int i = 0; i < c; i++)
        {
            scanf("%d", &t);
            for(int j = 0; j < t; j++)
                scanf("%d", &arr[j]);
            for(int j = m; j >= 0; j--)
            {
                dp[j] = false;
                for(int k = 0; k < t; k++)
                {
                    if(j-arr[k] < 0) continue;
                    dp[j] = dp[j-arr[k]];
                    if(dp[j]) break;
                }
            }
        }
        int mx = -1;
        for(int i = 0; i <= m; i++)
            if(dp[i]) mx = i;
        if(mx == -1)
            printf("no solution\n");
        else
            printf("%d\n", mx);
    }
    return 0;
}

