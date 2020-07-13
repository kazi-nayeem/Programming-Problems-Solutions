#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int dp[200][100];
int arr[200][100];
int len[200];
int n, mx;

int rec(int i, int j);

int main()
{
    //freopen("input.txt", "r", stdin);
    int ti, te;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        mx = n+n-1;
        for(int i = 0; i < n; i++)
        {
            len[i] = i;
            //printf("%d\n", len[i]);
            for(int j = 0; j <= i; j++)
                scanf("%d", &arr[i][j]);
        }
        for(int i = n; i < mx; i++)
        {
            len[i] = mx-i-1;
            //printf("%d\n", len[i]);
            for(int j = 0; j <= len[i]; j++)
                scanf("%d", &arr[i][j]);
        }
        /*printf("%d  %d\n", n, mx);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= len[i]; j++)
                printf("%d ", arr[i][j]);
            putchar('\n');
        }
        for(int i = n; i < mx; i++)
        {
            for(int j = 0; j <= len[i]; j++)
                printf("%d ", arr[i][j]);
            putchar('\n');
        }*/
        memset(dp,-1,sizeof dp);
        int result = rec(0,0);
        printf("Case %d: %d\n", te, result);
    }
    return 0;
}

int rec(int i, int j)
{
    //if(i >= mx || j < 0 || j > len[i]) return 0;
    int & res = dp[i][j];
    if(res != -1) return res;

    int ret1 = 0, ret2 = 0, ret3 = 0;
    if(i + 1< n)
    {
        if(len[i+1] > j)
            ret1 = rec(i+1,j+1);
    }
    else if(i +1 < mx && j > 0)
        ret2 = rec(i+1,j-1);
    if(i + 1< mx && j <= len[i+1])
        ret3 = rec(i+1,j);
    res = max(ret1, max(ret2,ret3))+arr[i][j];
    //printf("%d %d %d %d %d %d\n", i, j, ret1, ret2, ret3, res);
    return res;
}
