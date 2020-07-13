#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int dp[1<<15];
int cas[1<<15];
int kill[15];
int damage[15][15];
int n, te, ti;

int func(int mask, int kl);

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &kill[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%1d", &damage[i][j]);
        printf("Case %d: %d\n", te, func(0,0));
    }
    return 0;
}

int func(int mask, int kl)
{
    if(n == kl) return 0;
    int & res = dp[mask];
    if(cas[mask] == te) return res;
    cas[mask] = te;
    res = 200000000;
    int shot, ret;
    for(int i = 0; i < n; i++)
    {
        if((mask>>i)&1) continue;
        shot = 1;
        for(int j = 0; j < n; j++)
        {
            if((mask>>j)&1)
                if(shot < damage[j][i])
                    shot = damage[j][i];
        }
        ret = func((mask|(1<<i)), kl+1)+((kill[i]+shot-1)/shot);
        if(ret < res)
            res = ret;
    }
    return res;
}
