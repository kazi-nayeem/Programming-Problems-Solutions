//#include <bits/stdc++.h>

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
#include<map>
using namespace std;

#define MX 100005
#define inf 10000000000000000ll

typedef long long ll;
typedef unsigned long long ull;

int arr[3*MX];
ll dp[3*MX];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        dp[i] = inf;
    }
    sort(arr+1,arr+1+n);
    int mem = (n+k-1)/k;
    for(int i = 0; i < k; i++)
    {
        for(int j = n; j >= mem-1; j--)
        {
            dp[j] = min(dp[j],dp[j-mem+1]+arr[j]-arr[j-mem+2]);
            if(j>=mem)
                dp[j] = min(dp[j],dp[j-mem]+arr[j]-arr[j-mem+1]);
        }
        //for(int j = 0; j <= n; j++)
           // printf("%lld ", dp[j]);
        //puts("");
    }
    printf("%I64d\n", dp[n]);
    return 0;
}

