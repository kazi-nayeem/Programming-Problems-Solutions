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
#define inf 1000000000000ll

typedef long long ll;
typedef unsigned long long ull;

int arr[16][MX], total[16];
int dis[16][MX], n, m;
ll dp[1<<16];

ll func(int mask)
{
    if((1<<m) == mask+1) return 0;

    ll &res = dp[mask];

    if(res != -1) return res;
    res = inf;
    int pre = 0;
    for(int i = 0; i < m; i++)
        if((mask>>i)&1) pre += total[i];
    for(int i = 0; i < m; i++)
    {
        if((mask>>i)&1) continue;
        ll ret = func(mask | (1<<i))+dis[i][pre];
        res = min(res,ret);
    }
    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &m);
        int x;
        memset(dis,0,sizeof dis);
        memset(arr,0,sizeof arr);
        memset(dp,-1,sizeof dp);
        memset(total,0,sizeof total);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            x--;
            total[x]++;
            arr[x][i] = 1;
        }
        for(int i = 0; i < m; i++)
            for(int j = n-1; j >=0; j--)
            {
                if(arr[i][j] == 1)
                {
                    dis[i][j] = dis[i][j+1];
                }
                else
                {
                    dis[i][j] = dis[i][j+1]+arr[i][j+1];
                }
                arr[i][j] += arr[i][j+1];
            }
        ll res = func(0);
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}


