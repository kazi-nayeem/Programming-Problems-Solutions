/*
    Kazi Nayeem
    2012331027
    SUST
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long

int arr[1005][1005];
int res[1005][1005];

int main()
{
    int n, m;
    bool flag = false;
    while(scanf("%d%d", &n, &m) == 2)
    {
        if(flag) puts("");
        flag = true;
        for(int i = n; i > 0; i--)
            for(int j = 1; j <= n; j++)
                scanf("%d", &arr[i][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                arr[i][j] += arr[i][j-1];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                arr[j][i] += arr[j-1][i];
        for(int i = 1; i+m-1 <= n; i++)
            for(int k = 1; k+m-1 <= n; k++)
            {
                int j = i+m-1;
                int l = k+m-1;
                res[i][k] = arr[l][j]+arr[k-1][i-1]-arr[k-1][j]-arr[l][i-1];
            }
        //puts("\nres\n");
        ll int total = 0;
        for(int i = n-m+1; i>0; i--)
            for(int j = 1; j <= n-m+1; j++)
            {
                printf("%d\n", res[j][i]);
                total += res[j][i];
            }
        printf("%lld\n", total);
    }
    return 0;
}

