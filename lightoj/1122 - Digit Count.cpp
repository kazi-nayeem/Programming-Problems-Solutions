#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int arr[10];
int dp[10][10];
int m;

int func(int i, int pre);

int main()
{
    int te, ti, n, k;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        memset(arr,0, sizeof arr);
        memset(dp,-1, sizeof dp);

        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &k);
            arr[k] = 1;
        }
        printf("Case %d: %d\n", te, func(0,0));
    }
    return 0;
}

int func(int i, int pre)
{
    if(i >= m) return 1;

    int & res = dp[i][pre];
    if(res != -1) return res;
    int total = 0;
    if(i == 0)
    {
        for(int j = 1; j < 10; j++)
            if(arr[j] == 1)
            total += func(i+1,j);
    }
    else
    {
        int j = max(pre-2,1);
        int l = min(9,pre+2);
        for(;j<=l;j++)
            if(arr[j] == 1)
            total += func(i+1,j);
    }
    return res = total;
}
