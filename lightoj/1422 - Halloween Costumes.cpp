#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define ll long long
#define MX 100050
#define inf 1000000

int dp[102][102], now;
int cas[102][102];
int arr[102];

int func(int s, int e)
{
    if(s > e) return 0;
    if(s == e) return 1;

    int &res = dp[s][e];
    if(cas[s][e] == now) return res;
    cas[s][e] = now;
    res = 1+func(s+1,e);
    for(int i = s+1; i <= e; i++)
        if(arr[s] == arr[i])
        res = min(res,func(s+1,i-1)+func(i,e));
    return res;
}

int main()
{
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        now++;
        printf("Case %d: %d\n", te, func(0,n-1));
    }
    return 0;
}
