#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 10002
#define lli long long int


lli dp[MAX][21];
int coin[21];

lli coinchange(int i, int n);

int main()
{
    int n;
    for(n = 0; n < 21;)
    {
        n++;
        coin[n-1] = n * n * n;
        //printf("%d\n", coin[n-1]);
    }
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &n) == 1)
        printf("%lld\n", coinchange(0,n));

    return 0;
}

lli coinchange(int i, int n)
{
    if(i >= 21)
    {
        if(n == 0) return 1;
        return 0;
    }

    if(dp[n][i] != -1) return dp[n][i];

    lli ret1 = 0, ret2;
    if(n - coin[i] >= 0)
        ret1 = coinchange(i, n - coin[i]);
    ret2 = coinchange(i+1, n);

    return dp[n][i] = ret1 + ret2;
}

