#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n, arr[105];
int dp[103][103][103];

int func(int pos, int left, int right);

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
        printf("Case %d: %d\n", te, func(1,0,n+1));
    }
    return 0;
}

int func(int pos, int left, int right)
{
    if(pos > n) return 0;

    int & res = dp[pos][left][right];
    if(res != -1) return res;

    if(arr[pos] <= arr[right] && arr[pos] >= arr[left])
        res = max(func(pos+1,pos,right), func(pos+1,left,pos))+1;
    res = max(res, func(pos+1,left,right));
    //printf("%d %d %d %d\n", pos, left, right, res);
    return res;
}
