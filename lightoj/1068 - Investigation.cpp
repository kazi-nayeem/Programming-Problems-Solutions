#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define ll int

char str[25];
int len, a, b, m;
ll dp[11][84][84][2];

ll func(int pos, int mod, int digt, int flag);

int main()
{
    int te, ti;

    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d %d", &a, &b, &m);
        sprintf(str,"%d", b);
        len = strlen(str);
        memset(dp,-1,sizeof dp);
        ll result = func(0,0,0,1);
        sprintf(str,"%d", a-1);
        len = strlen(str);
        memset(dp,-1,sizeof dp);
        ll result2 = func(0,0,0,1);
        printf("Case %d: %d\n", te, result-result2);
    }
    return 0;
}

ll func(int pos, int mod, int digt, int flag)
{
    if(m > 83) return 0;
    if(pos >= len)
    {
        if(mod == 0 && digt == 0) return 1;
        return 0;
    }

    ll & res = dp[pos][mod][digt][flag];
    if(res != -1) return res;

    int mx = (flag)?(str[pos]-'0'):9;
    ll ret = 0;
    for(int i = 0; i <= mx; i++)
    {
        ret += func(pos+1,(mod+i)%m, (digt*10+i)%m ,flag&(str[pos] == (i+'0')));
    }
    return res = ret;
}
