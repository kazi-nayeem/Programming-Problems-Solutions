#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define MX 3005
#define ll long long

int arr[505][505];
int mod, col;
int sum[3];
int dp[502][502][502];

int rec(int row, int zero, int one)
{
    if(row == 0)
    {
        if(zero == 0 && one == 0) return 1;
        return 0;
    }
    if(zero < 0 || one < 0) return 0;
    int & res = dp[row][zero][one];
    if(res != -1) return res;
    res = ((one*(one-1)/2)*rec(row-1,zero,one-2))%mod;
    res += (one*zero)*rec(row-1,zero-1,one);
    res %= mod;
    res += (zero*(zero-1)/2)*rec(row-1,zero-2,one+2);
    res %= mod;
    return res;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int res = 0;
    int n, m;
    scanf("%d%d%d", &n, &m, &mod);
    for(int i = 0; i < m; i++)
    {
        int total = 0;
        for(int j = 0; j < n; j++)
        {
            scanf("%1d", &arr[i][j]);
            total += arr[i][j];
        }
        if(total != 2)
            res = -1;
    }
    if(res == -1)
    {
        printf("0\n");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        int total = 0;
        for(int j = 0; j < m; j++)
            total += arr[j][i];
        if(total > 2)
        {
            res = -1;
            break;
        }
        else
            sum[total]++;
    }
    if(res == -1)
    {
        printf("0\n");
        return 0;
    }
    //printf("%d %d %d\n", sum[0], sum[1], sum[2]);
    printf("%d\n", rec(n-m,sum[0],sum[1]));
    return 0;
}
