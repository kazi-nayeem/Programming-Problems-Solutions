#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 70
#define lli long long int

lli dp[MX][MX][2];

lli chest(int pos, int tak, int pre);

int main()
{
    int n, s;
    while(scanf("%d %d", &n, &s) == 2)
    {
        if(n < 0 || s < 0) return 0;

        memset(dp, -1, sizeof (dp));
        printf("%lld\n", chest(n,s,1));
    }
    return 0;
}

lli chest(int pos, int tak, int pre)
{
    if(tak<0) return 0;
    if(pos == 0)
    {
        if(tak == 0) return 1;
        return 0;
    }

    lli & res = dp[pos][tak][pre];
    if(res != -1) return res;

    lli ret1 = 0, ret2 = 0;
    if(pre == 1)
    {
        ret1 = chest(pos-1,tak-1,1);
        ret2 = chest(pos-1,tak,0);
    }
    else
    {
        ret1 = chest(pos-1,tak, 1);
        ret2 = chest(pos-1,tak,0);
    }

    return res = ret1+ret2;
}
