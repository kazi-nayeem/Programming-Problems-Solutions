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

int arr[105][105];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            arr[i][j] += arr[i][j-1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            arr[j][i] += arr[j-1][i];
    int mx = -1000000000;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            for(int k = 1; k <= n; k++)
                for(int l = k; l <= n; l++)
                {
                    int sum = arr[l][j]+arr[k-1][i-1]-arr[k-1][j]-arr[l][i-1];
                    if(sum > mx)
                            mx = sum;
                }
    printf("%d\n", mx);
    return 0;
}

