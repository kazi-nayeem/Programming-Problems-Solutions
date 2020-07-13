#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long int

struct data
{
    ll nz, ns;
    data() {}
    data(ll a, ll b): nz(a), ns(b) {}
};

data dp[11][2][2];
int n;
char str[25];

data func(int pos, int flag, int zero);

int main()
{
    int te, ti;
    ll x, y;
    scanf("%d", &ti);

    for(te = 1; te<= ti; te++)
    {
        scanf("%lld %lld", &x, &y);
        sprintf(str,"%lld", y);
        n = strlen(str);
        memset(dp,-1,sizeof dp);
        ll rets = func(0,1,0).nz+1, rets2 = 0;
        if(x>0)
        {
            sprintf(str,"%lld", x-1);
            n = strlen(str);
            memset(dp,-1,sizeof dp);
            rets2 = func(0,1,0).nz+1;
        }
        //printf("%lld %lld\n", rets, rets2);
        printf("Case %d: %lld\n", te, rets-rets2);
    }
}

data func(int pos, int flag, int zero)
{
    if(pos >= n)
        return data(0,1);

    data & res = dp[pos][flag][zero];
    if(res.nz != -1) return res;

    int mx = (flag)? (str[pos]-'0') : 9;
    //if(flag) printf(" %d\n", mx);
    ll ret1 = 0, ret2 = 0;
    if(zero == 0)
    {
        ret1 = func(pos+1,flag&&(str[pos] == '0'),0).nz;
        ret2 = func(pos+1,flag&&(str[pos] == '0'),0).ns;
    }
    else
    {
        ret1 = func(pos+1,flag&&(str[pos] == '0'),1).nz+func(pos+1,flag&&(str[pos] == '0'),1).ns;
        ret2 = func(pos+1,flag&&(str[pos] == '0'),1).ns;
    }
    for(int i = 1; i <= mx; i++)
    {
        ret1 += func(pos+1,flag&&(str[pos] == ('0'+i)),1).nz;
        ret2 += func(pos+1,flag&&(str[pos] == ('0'+i)),1).ns;
    }
    //printf("r1 %d\n", ret1);
    return res = data(ret1,ret2);
}


