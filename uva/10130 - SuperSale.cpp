#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int obj[1005], weight[1005];
int dp[1001][31];

int sale(int i, int w);

int main()
{
    //freopen("input.txt", "r", stdin);
    int ti, n, p;
    scanf("%d", &ti);

    while(ti--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", obj+i, weight+i);
        scanf("%d", &p);
        memset(dp,-1,sizeof dp);
        int total = 0, mw;
        for(int i = 0; i < p; i++)
        {
            scanf("%d", &mw);
            total += sale(n-1,mw);
        }
        printf("%d\n", total);
    }
    return 0;
}

int sale(int i, int w)
{
    if(i < 0) return 0;
    int& res = dp[i][w];
    if(res != -1) return res;

    int ret1 = 0, ret2 = 0;
    if(weight[i] <= w)
        ret1 = sale(i-1,w-weight[i])+obj[i];
    ret2 = sale(i-1,w);
    return res = max(ret1,ret2);
}
