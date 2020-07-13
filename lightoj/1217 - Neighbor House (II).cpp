#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n, f;
int arr[1005];
int dp[1005];

int func(int i);

int main()
{
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", arr+i);
        memset(dp,-1,sizeof dp);
        f = 1;
        int k = func(0);
        f = 0;
        memset(dp,-1,sizeof dp);
        k = max(func(1),k);
        k = max(func(2),k);
        printf("Case %d: %d\n", te, k);
    }

    return 0;
}

int func(int i)
{
    if(i + f>= n) return 0;

    if(dp[i] != -1) return dp[i];
    int ret = func(i+2)+arr[i];
    ret = max(ret,func(i+3)+arr[i]);

    return dp[i] = ret;
}
