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

data dp[33][2][2];
int n;

data func(int pos, int flag, int pre);

int main()
{
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te<= ti; te++)
    {
        scanf("%d", &n);
        int pos = 31;
        for(; pos >= 0; pos--)
            if((n>>pos))
                break;
        memset(dp,-1,sizeof dp);
        ll rets = func(pos,1, 0).nz;
        printf("Case %d: %lld\n", te, rets);
    }
}

data func(int pos, int flag, int pre)
{
    if(pos < 0)
        return data(0,1);

    data & res = dp[pos][flag][pre];
    if(res.nz != -1) return res;

    int po = (n>>pos)&1;
    //printf("%d\n", po);
    int mx = (flag) ? po:1;
    ll ret1 = 0, ret2 = 0;
    if(mx)
    {
        if(pre)
        {
            ret1 = func(pos-1,flag&po,1).nz+func(pos-1,flag&po,1).ns;
            ret2 = func(pos-1,flag&po,1).ns;
        }
        else
        {
            ret1 = func(pos-1,flag&po,1).nz;
            ret2 = func(pos-1,flag&po,1).ns;
        }
    }
    ret1 += func(pos-1,flag&(po == 0), 0).nz;
    ret2 += func(pos-1,flag&(po == 0), 0).ns;
    return res = data(ret1,ret2);
}
