#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 50

char str[MX][MX];
char match[MX];
int flag[MX], now, n, m;
char cat[MX];
char an[MX];

bool bpm(int k)
{
    if(cat[k] == 0) return false;

    for(int i = 0; i < m; i++)
    {
        if(str[k][i] == '1' || an[i] == 0) continue;
        if(flag[i] == now) continue;
        flag[i] = now;
        if(match[i] == -1 || bpm(match[i]))
        {
            match[i] = k;
            return true;
        }
    }
    return false;
}

int func()
{
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(str[i][j] == '0') continue;
            memset(cat,0,sizeof cat);
            memset(an,0,sizeof an);
            int total = 0;

            for(int k = 0; k < m; k++)
                if(str[i][k] == '1')
                {
                    an[k] = 1;
                    total++;
                }

            for(int k = 0; k < n; k++)
                if(str[k][j] == '1')
                {
                    cat[k] = 1;
                    total++;
                }

            memset(match,-1,sizeof match);

            for(int k = 0; k < n; k++)
            {
                now++;
                if(bpm(k)) total--;
            }
            res = max(res,total);
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
        scanf("%d %d", &n, &m);
        gets(str[0]);
        for(int i = 0; i < n; i++)
            gets(str[i]);
        printf("Case %d: %d\n", te, func());
    }
    return 0;
}
