#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int x[17], y[17];
int dp[1<<16], n;
int sav[1<<16], cas;
bool flag[16][16][16];

int func(int mask);

int main()
{
    int te, ti;

    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", x+i, y+i);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    flag[i][j][k] = (y[k]-y[i])*(x[i]-x[j]) != (y[i]-y[j])*(x[k]-x[i]);
        cas = te;
        printf("Case %d: %d\n",te, func(0));
    }
    return 0;
}

int func(int mask)
{
    if(__builtin_popcountl(mask) == n) return 0;
    int &res = dp[mask];
    if(sav[mask] == cas) return res;
    sav[mask] = cas;
    res = 100;
    int tk = mask;
    for(int i = 0; i < n; i++)
    {
        if((mask>>i)&1) continue;
        res = min(res,func(mask | (1<<i))+1);
        for(int j = i+1; j < n; j++)
        {
            int m = mask | (1<<i);
            if((tk>>j)&1) continue;
            m = m | (1<<j);
            for(int k = j+1; k < n; k++)
            {
                if((m>>k)&1) continue;
                if(flag[i][j][k]) continue;
                m = m | (1 << k);
            }
            tk |= m;
            res = min(res, func(m)+1);
        }
        break;
    }
    return res;
}
