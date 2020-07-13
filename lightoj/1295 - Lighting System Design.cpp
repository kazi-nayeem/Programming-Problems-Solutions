#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
#define MX 1005

struct data{
    int v, k, c, l;
    bool operator < (const data & p) const
    {
        return v<p.v;
    }
};

data arr[MX];
ll dp[MX];

ll func(int pos)
{
    if(pos == 0) return 0;
    ll & res = dp[pos];
    if(res != -1) return res;
    res = 100000000000000ll;
    for(int i = 1; i <= pos; i++)
    {
        res = min(res,(ll) func(i-1)+arr[pos].k+(arr[pos].c*(arr[pos].l-arr[i-1].l)));
    }
    return res;
}

int main()
{
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d %d", &arr[i].v, &arr[i].k, &arr[i].c, &arr[i].l);
        sort(arr+1,arr+1+n);
        for(int i = 2; i <= n; i++)
            arr[i].l += arr[i-1].l;
        arr[0].l = 0;
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n", te, func(n));
    }
    return 0;
}

/**
2
3
100 500 10 20
120 600 8 16
220 400 7 18
3
100 500 10 20
120 600 8 16
220 400 7 19
*/
