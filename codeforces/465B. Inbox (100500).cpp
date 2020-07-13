#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 1005

int dp[MX];
int arr[MX];
int n;

int rec(int pos)
{
    if(pos == n) return 0;
    int & res = dp[pos];
    if(res != -1) return res;
    res = 10000;
    for(int i = pos+1; i <= n; i++)
    {
        if(arr[i] == 1)
        {
            res = rec(i)+2;
            break;
        }
    }
    res = min(res,rec(pos+1)+1);
    return res;
}

int main()
{
    scanf("%d", &n);
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int res = 0;
    int t = n;
    for(n = n-1; arr[n] == 0; n--);
    for(int i = 0; i <= n; i++)
    {
        if(arr[i] == 1)
        {
            res = rec(i)+1;
            break;
        }
    }
    printf("%d\n", res);
    return 0;
}
