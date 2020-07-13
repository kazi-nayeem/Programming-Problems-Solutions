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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll flag[MX];
ll dp1[MX];
ll dp2[MX];
ll arr[MX];

int main()
{
    ll n, t;
    scanf("%I64d %I64d", &n, &t);
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d", &arr[i]);
        arr[i+n] = arr[i];
        flag[arr[i]]++;
    }
    for(int i = 1; i <= 2*n; i++)
    {
        //printf("%I64d ", arr[i]);
        dp1[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(arr[i] >= arr[j])
                dp1[i]=max(dp1[i],dp1[j]+1);
        }
    }
    /*puts("");
    for(int i = 1; i <= 2*n; i++)
        printf("%I64d ", dp1[i]);
    puts("");*/
    for(int i = 2*n; i >= 1; i--)
    {
        dp2[i] = 1;
        for(int j = i+1; j <= 2*n; j++)
        {
            if(arr[i] <= arr[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }
    /*for(int i = 1; i <= n; i++)
        printf("%I64d ", dp2[i]);
    puts("");*/
    ll res = 0;
    if(t > 3ll)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(arr[i] <= arr[j])
                {
                    res = max(res,dp1[i]+dp2[j]+((t-3)*flag[arr[i]]));
                    //printf("%I64d %I64d %I64d %I64d\n", )
                }
            }
        }
        for(int i = n+1; i <= 2*n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(arr[i] <= arr[j])
                {
                    res = max(res,dp1[i]+dp2[j]+((t-4)*flag[arr[i]]));
                    //printf("%I64d %I64d %I64d %I64d\n", )
                }
            }
        }
    }
    if(t >= 3ll)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = n+1; j <= 2*n; j++)
            {
                if(arr[i] <= arr[j])
                {
                    res = max(res,dp1[i]+dp2[j]+((t-2)*flag[arr[i]]));
                    //printf("%I64d %I64d %I64d %I64d\n", )
                }
            }
        }
        for(int i = n+1; i <= 2*n; i++)
        {
            for(int j = n+1; j <= 2*n; j++)
            {
                if(arr[i] <= arr[j])
                {
                    res = max(res,dp1[i]+dp2[j]+((t-3)*flag[arr[i]]));
                    //printf("%I64d %I64d %I64d %I64d\n", )
                }
            }
        }
    }
    if(t == 2ll) res = 1;
    for(int i = 1; i <= 2*n; i++)
        res = max(res,dp1[i]);
    if(t == 1ll) res = 1;
    for(int i = 1; i <= n; i++)
        res = max(res,dp1[i]);
    printf("%I64d\n", res);
    return 0;
}


