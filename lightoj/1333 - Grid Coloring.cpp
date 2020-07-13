#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long


struct data
{
    int x, y;
    data() {}
    data(int a, int b)
    {
        x = a;
        y = b;
    }
    bool operator < (const data& p) const
    {
        if(y != p.y) return y<p.y;
        return x<p.x;
    }
};

const ll mod = 1000000000ll;

data arr[502];
int te, ti, row, col, k, b, u, v;
ll all;

ll bigmod(ll a, int p)
{
    if(p == 0) return 1;
    if(p%2 == 1)
        return (a*bigmod(a,p-1))%mod;
    ll res = bigmod(a,p/2);
    return (res*res)%mod;
}

ll calc( void )
{
    sort(arr,arr+b);
    ll res = 1;
    res = bigmod(all,arr[0].y-1);
    if(arr[0].x > 1)
    {
        res = (res*k)%mod;
        res = (res*bigmod(k-1,arr[0].x-2))%mod;
    }
//    printf("%lld\n", res);
    for(int i = 1; i < b; i++)
    {
        if(arr[i].y == arr[i-1].y)
        {
            if(arr[i].x-arr[i-1].x >= 2)
            {
                res = (res*k)%mod;
                res = (res*bigmod(k-1,arr[i].x-arr[i-1].x-2))%mod;
            }
            //printf("tk %d %lld\n",i, res);
        }
        else
        {
            if(arr[i-1].x < row)
            {
                res = (res*k)%mod;
                res = (res*bigmod(k-1,row-arr[i-1].x-1))%mod;
            }
            if(arr[i].x > 1)
            {
                res = (res*k)%mod;
                res = (res*bigmod(k-1,arr[i].x-2))%mod;
            }
            res = (res*bigmod(all,arr[i].y-arr[i-1].y-1))%mod;
        }
//        printf("tk %d %lld\n",i, res);
    }
    if(arr[b-1].x < row)
    {
        res = (res*k)%mod;
        res = (res*bigmod(k-1,row-arr[b-1].x-1))%mod;
    }
    //printf("%lld\n", res);
    res = (res*bigmod(all,col-arr[b-1].y))%mod;
    return res;
}

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &row, &col, &k, &b);
        for(int i = 0; i < b; i++)
            scanf("%d%d", &arr[i].x, &arr[i].y);
        ll res;
        all = (k*bigmod(k-1,row-1))%mod;
        if(b == 0)
            res = bigmod(all,col);
        else
            res = calc();
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
