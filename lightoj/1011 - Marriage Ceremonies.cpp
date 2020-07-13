#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int arr[16][16], tak[16];
int n;
int dp[1<<17];

int backtrack(int i,int sum);

int main()
{
    int ti, te;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

        memset(dp,-1,sizeof(int) * (2<<n));
        int maxi = backtrack(0,0);
        printf("Case %d: %d\n", te, maxi);
    }
    return 0;
}

int backtrack(int i,int sum)
{
    //printf("%d %d  ", i, sum);
    if(i >= n) return 0;
    int & res = dp[sum];
    if(res != -1) return res;
    //printf("ok\n");
    int ret = 0;
    for(int j = 0; j < n; j++)
    {
        //printf("%d %d  ", (sum>>j) & 1, j);
        if((sum>>j) & 1 == 1) continue;
        //printf("ok\n");
        ret = max(ret, (backtrack(i+1, sum | (1<<j))+arr[i][j]));
    }
    return res = ret;
}
