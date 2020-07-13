#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 200005
#define MXP 4794
#define ll long long

int arr[1005];

int main()
{
    int n, l;
    scanf("%d%d", &n, &l);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr,arr+n);
    double mx = arr[0];
    mx = max(mx,(double) l-arr[n-1]);
    for(int i = 1; i <= n; i++)
    {
        mx = max(mx,(double) (arr[i]-arr[i-1])/2);
    }
    printf("%.10lf\n", mx);
    return 0;
}
