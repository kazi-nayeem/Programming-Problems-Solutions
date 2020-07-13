#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int dp[21][3], arr[21][3];
int n;

int func(int i, int j);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti, result;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        result = 201000;
        memset(dp,-1, sizeof dp);        for(int i = 0; i < 3; i++)
            result = min(result, func(1,i)+arr[0][i]);
        printf("Case %d: %d\n", te, result);
    }
    return 0;
}


int func(int i, int j)
{
    if(i >= n) return 0;

    int & res = dp[i][j];
    if(res != -1) return res;

    int a = (j+1)%3, b = (j+2)%3;
    int ret1 = func(i+1,a)+arr[i][a];
    int ret2 = func(i+1, b)+arr[i][b];
    res = min(ret1,ret2);
    return res;
}
