#include<cstdio>
#include<cstring>
using namespace std;

struct data{int nz, ns;
    data(){}
    data(int a, int b): nz(a), ns(b){}
};

data dp[33][2];
int n;

data func(int pos, int flag);

int main()
{
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te<= ti; te++)
    {
        scanf("%d", &n);
        int pos = 31;
        for(;pos >= 0;pos--)
            if((n>>pos))
            break;
        memset(dp,-1,sizeof dp);
        int rets = func(pos,1).nz;
        printf("%d\n", rets);
    }
}

data func(int pos, int flag)
{
    if(pos < 0)
        return data(0,1);

    data & res = dp[pos][flag];
    if(res.nz != -1) return res;

    int po = (n>>pos)&1;
    printf("%d\n", po);
    int mx = (flag) ? po:1;
    int ret1 = 0, ret2 = 0;
    if(mx)
    {
        ret1 = func(pos-1,flag&po).nz;
        ret2 = func(pos-1,flag&po).ns;
    }
    ret1 += func(pos-1,flag&(po == 0)).nz+func(pos-1,flag&(po == 0)).ns;
    ret2 += func(pos-1,flag&(po == 0)).ns;
    return res = data(ret1,ret2);
}

