#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int dp[10005];
int weight[101], price[101];

int main()
{
    int te, ti, cancarry, n, need, total, maxi, tem;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &cancarry);
        total = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d", price+i, &need, weight+i);
            total += (need*weight[i]);
        }

        if(total > cancarry)
        {
            printf("Case %d: Impossible\n", te);
            continue;
        }

        maxi = cancarry - total;
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; i++)
        {
            for(int j = weight[i]; j <= maxi; j++)
            {
                tem = dp[j-weight[i]]+price[i];
                if(dp[j] < tem) dp[j] = tem;
            }
        }
        int ma = 0;
        for(int i = 0; i <= maxi ; i++)
            if(ma < dp[i]) ma = dp[i];
        printf("Case %d: %d\n", te, ma);
    }
    return 0;
}

