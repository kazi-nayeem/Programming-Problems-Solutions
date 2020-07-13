#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define MX 100005

double dp[MX];

double func(int n)
{
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];
    int root = sqrt(n)+1;
    dp[n] = 2;
    int k = 2;
    for(int i = 2; i < root; i++)
    {
        if(n%i != 0) continue;
        dp[n] += 1+func(n/i);
        k++;
        if(i*i != n)
        {
            dp[n] += 1+func(i);
            k++;
        }
    }
    dp[n] /= (k-1);
    return dp[n];
}

int main()
{
    for(int i = 0; i < MX; i++) dp[i] = -1;
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        printf("Case %d: %.8lf\n", te, func(n));
    }
    return 0;
}
