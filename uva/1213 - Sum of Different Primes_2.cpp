#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

#define MX 1122
#define MXP 188

int flag[MX];
int prime[MXP];
int dp[MX][MXP][15];

void sieve(void);

int main()
{
    sieve();
    memset(dp,0,sizeof dp);
    dp[0][0][0] = 1;
    for(int k = 1; k < 15; k++)
        for(int i = 0; i<MXP; i++)
            for(int j = MX-1; j >= 2; j--)
                {
                    dp[j][i][k] = dp[j][i-1][k];
                    if(j >= prime[i])
                        dp[j][i][k] += dp[j-prime[i]][i-1][k-1];
                }
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        if(n == 0 && k == 0) return 0;
        //for(int i = 0; i < MXP; i++)
        printf("%d\n", dp[n][MXP-1][k]);
    }
    return 0;
}

void sieve(void)
{
    prime[1] = 2;
    int k = 2;
    for(int i = 3; i < MX; i += 2)
    {
        if(flag[i] == 0)
        {
            prime[k++] = i;
            int ad = i << 1;
            for(int j = i * i; j < MX; j+=ad)
                flag[j] = 1;
        }
    }
    //printf("%d\n", k);
    //for(int i = k-1; i > 100; i--)
       // printf("%d %d\n", i, prime[i]);
    return;
}
