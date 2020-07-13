#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int my[51], opp[51];
int dp[51][51];

int func(int i, int j);

int main()
{
    int n, te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", my+i);
        for(int i = 0; i < n; i++) scanf("%d", opp+i);
        sort(my,my+n);
        sort(opp,opp+n);
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n", te, func(n-1,n-1));
    }
    return 0;
}

int func(int i, int j)
{
    if(i < 0 || j < 0)  return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(my[i] > opp[j])
        dp[i][j] = max(dp[i][j], func(i-1,j-1)+2);
    if(my[i] == opp[j])
        dp[i][j] = max(dp[i][j], func(i-1,j-1)+1);
    dp[i][j] = max(dp[i][j], max(func(i-1,j),func(i,j-1)));
    return dp[i][j];
}
