#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 30005
#define lli long long int
int coin[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
lli dp[MAX][11];

lli coinchang(int i, int n);

int main()
{
    int n, k, in;
    lli total;
    memset(dp, -1, sizeof(dp));
    while(scanf(" %d.%d", &n, &k) == 2)
    {
        in = (n * 100) + k;
        if(in == 0) return 0;
        total = coinchang(0,in);
        printf("%3d.%02d%17lld\n", n, k, total);
        //printf("%d\n", n);
    }
    return 0;
}

lli coinchang(int i, int n)
{
    if(i >= 11)
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
