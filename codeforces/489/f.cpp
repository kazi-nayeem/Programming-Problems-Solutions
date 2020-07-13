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
ll int mod;
int col;
int sum[3];
ll int dp[502][502];

ll int rec(int zero, int one)
{
    if(zero == 0 && one == 0) return 1;
    if(zero < 0 || one < 0) return 0;
    if(zero+one > col) return 0;
    ll int & res = dp[zero][one];
    if(res != -1) return res;
    res = (ll)((one*(one-1)/2)*rec(zero,one-2));
    res += (ll)(one*zero)*rec(zero-1,one);
    res += (ll)(zero*(zero-1)/2)*rec(zero-2,one+2);
    res %= mod;
    return res;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int res = 0;
    int n, m;
    scanf("%d%d%I64d", &n, &m, &mod);
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
    col = n;
    //printf("%d %d %d\n", sum[0], sum[1], sum[2]);
    printf("%I64d\n", rec(sum[0],sum[1]));
    return 0;
}
