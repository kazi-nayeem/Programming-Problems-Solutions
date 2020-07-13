#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long int

struct data{ll nz, ns;
    data(){}
    data(int a, int b): nz(a), ns(b){}
};

data dp[33][2];
int n;
char str[25];

data func(int pos, int flag);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    gets(str);
    for(te = 1; te<= ti; te++)
    {
        gets(str);
        puts(str);
        n = strlen(str);
        memset(dp,-1,sizeof dp);
        ll rets = func(0,1).nz;
        printf("%d\n", rets);
    }
}

data func(int pos, int flag)
{
    if(pos >= n)
        return data(0,1);

    data & res = dp[pos][flag];
    if(res.nz != -1) return res;

    int mx = (flag)? (str[pos]-'0') : 9;
    ll ret1 = 0, ret2 = 0;
    ret1 = func(pos+1,flag&(str[pos] == '0')).nz+func(pos+1,flag&(str[pos] == '0')).ns;
    ret2 = func(pos+1,flag&(str[pos] == '0')).ns;
    for(int i = 1; i <= mx; i++)
    {
        ret1 += func(pos+1,flag&(str[pos] == ('0'+i))).nz;
        ret2 += func(pos+1,flag&(str[pos] == ('0'+i))).ns;
    }
    return res = data(ret1,ret2);
}


