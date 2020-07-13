#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int point[105], dp[101][101], w;

int func(int p, int k)
{
    if(p < 0 || k == 0) {
            return 0;
    }
    if(dp[p][k] != -1) return dp[p][k];
    dp[p][k] = func(p-1,k);
    int i;
    for(i = p-1;point[i]+w>=point[p] && i >= 0;i--);
    dp[p][k] = max(dp[p][k], func(i,k-1)+p-i);
    return dp[p][k];
}

int main()
{
    int te, ti, tm, n, k;
    scanf("%d", &ti);

    for(te = 1 ; te <= ti; te++)
    {
        scanf("%d%d%d", &n, &w, &k);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &tm, point+i);

        sort(point,point+n);
        memset(dp,-1,sizeof dp);

        printf("Case %d: %d\n", te, func(n-1,k));
    }
    return 0;
}
