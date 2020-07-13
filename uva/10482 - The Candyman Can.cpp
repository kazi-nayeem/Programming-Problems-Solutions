#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 650

int arr[32];
int dp[MX][MX];
int n, total, mini;

void can(void);
int check(int i, int j);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        mini = 1000;
        can();
        printf("Case %d: %d\n", te, mini);
    }
    return 0;
}

void can(void)
{
    for(int i = 0; i <= total; i++)
        for(int j = 0; j <= total; j++)
        dp[i][j] = 0;
    dp[0][0] = 1;
    for(int k = 0; k < n; k++)
    for(int i = total; i >= 0; i--)
        for(int j = total; j >= 0; j--)
        {
            if(dp[i][j]) continue;
            if(i >= arr[k])
                dp[i][j] = dp[i-arr[k]][j];
            if(dp[i][j] == 0 && j>=arr[k])
                dp[i][j] = dp[i][j-arr[k]];
            if(dp[i][j])
            {
                mini = min(mini,check(i,j));
            }
        }
    return;
}

int check(int i, int j)
{
    int k = total - i - j;
    if(i > j)
        i ^= j ^= i ^= j;
    if(i > k)
        i ^= k ^= i ^= k;
    if(j > k)
        j ^= k ^= j ^= k;
    return k - i;
}
