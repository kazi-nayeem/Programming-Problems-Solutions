#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

#define MX 1122
#define MXP 187

int flag[MX];
int prime[MXP];
int dp[MX][MXP][15];

int func(int sum, int pos, int tak);
void sieve(void);

int main()
{
    sieve();
    memset(dp,-1,sizeof dp);
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        if(n == 0 && k == 0) return 0;
        printf("%d\n", func(n,MXP-1,k));
    }
    return 0;
}

int func(int sum, int pos, int tak)
{
    if(pos < 0)
    {
        if(sum == 0 && tak == 0) return 1;
        return 0;
    }

    int &res = dp[sum][pos][tak];
    if(res != -1) return res;
    int ret1 = 0, ret2 = 0;
    if(sum >= prime[pos] && tak > 0)
        ret1 = func(sum - prime[pos], pos-1, tak-1);
    ret2 = func(sum, pos-1, tak);
    res = ret1+ret2;
    //printf("%d %d %d %d\n", sum, pos, tak, dp[sum][pos][tak]);
    return res;
}

void sieve(void)
{
    prime[0] = 2;
    int k = 1;
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
