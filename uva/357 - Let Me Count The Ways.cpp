#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 30005
#define lli long long int
int coin[] = {1,5,10,25,50};
lli dp[MAX][5];

lli coinchang(int i, int n);

int main()
{
    int n;
    lli total;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &n) == 1)
    {
        total = coinchang(0,n);
        if(total == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", total, n);
    }
    return 0;
}

lli coinchang(int i, int n)
{
    if(i >= 5)
    {
        if(n == 0) return 1;
        return 0;
    }
    if(dp[n][i] != -1) return dp[n][i];
    lli ret1 = 0, ret2;
    if(n-coin[i] >= 0) ret1 = coinchang(i,n-coin[i]);
    ret2 = coinchang(i+1,n);
    return dp[n][i] = ret1+ret2;
}
