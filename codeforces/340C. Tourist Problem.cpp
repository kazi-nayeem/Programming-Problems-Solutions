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

#define ll long long
#define MX 100005

ll arr[MX];
ll dp[MX];

int main()
{
    ll int n;
    ll res = 0;
    scanf("%I64d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &arr[i]);
        res += arr[i];
    }
    sort(arr,arr+n);
    for(int i = n-2; i >= 0; i--)
        dp[i] = dp[i+1] + (n-i-1)*(arr[i+1]-arr[i]);
    ll total = 0;
    for(int i = 0; i < n; i++)
    {
        total += i*(arr[i] - arr[i-1]);
        res += total+dp[i];
    }
    ll gcd = __gcd(res,n);
    printf("%I64d %I64d\n", res/gcd, n/gcd);
    return 0;
}

