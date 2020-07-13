#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n, arr[105];
int dp[103][103];

int func(int left, int right);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        memset(dp,-1,sizeof dp);
        arr[0] = 0;
        arr[n+1] = 105000;
        printf("Case %d: %d\n", te, func(0,n+1));
    }
    return 0;
}

int func(int left, int right)
{
    int & res = dp[left][right];
    if(res != -1) return res;
    res = 0;
    int fr = min(left,right),to = max(left,right);
    for(fr++; fr < to; fr++)
    if(arr[fr] <= arr[right] && arr[fr] >= arr[left])
        res = max(res, max(func(fr,right)+1, func(left,fr)+1));
    //printf("%d %d %d %d\n", pos, left, right, res);
    return res;
}

