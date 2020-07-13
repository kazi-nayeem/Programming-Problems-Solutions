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
#define inf 100000000

int adj[20][20];
int dp[1<<15];
int node;

int generat(int pre, int mask);

int func(int mask)
{
    if((mask+1) == (1<<node)) return 0;
    int & res = dp[mask];
    if(res != -1) return res;
    res = inf;
    for(int i = 0; i < node; i++)
    {
        if((mask>>i)&1) continue;
        res = min(res,generat(mask,1<<i,st)+1);
    }
    return res;
}

int generat(int pre, int mask, int st)
{
    int res = func(pre|mask);
    int flag = 0;
    for(int i = 0; i < node; i++)
    {
        if(((mask>>i)&1) == 0) continue;
        for(int j = st; j < node; j++)
        {
            if(adj[i][j] == 0) continue;
            if((flag>>j)&1) continue;
            if((mask>>j)&1) continue;
            if((pre>>j)&1) continue;

            flag |= (1<<j);
            res = min(res,generat(pre,mask | (1<<j),));
        }
    }
    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int edge, u, v;
        scanf("%d %d", &node, &edge);
        memset(adj,0,sizeof adj);
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < edge; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u-1][v-1] = 1;
        }
        printf("Case %d: %d\n", te, func(0));
    }
    return 0;
}
