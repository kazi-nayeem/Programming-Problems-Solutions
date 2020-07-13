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
#include<bitset>
using namespace std;

#define MX 500005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[MX];
ll dp[MX];


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    sort(arr+1,arr+n+1);
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1],dp[i-2]+min(arr[i],arr[i-1]));
        //printf("%lld ", dp[i]);
    }
    printf("%I64d\n", dp[n]);
    return 0;
}


