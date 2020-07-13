#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

#define MX 100005

typedef long long ll;

int arr1[MX];
int arr2[MX];
int dp[MX];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);
    sort(arr1,arr1+n);
    sort(arr2,arr2+m, greater<int> ());
    ll res = 0;
    for(int i = 0; i < min(n,m) && arr2[i] > arr1[i]; i++)
    {
        res += abs(arr1[i]-arr2[i]);
    }
    cout<<res<<endl;
    return 0;
}
