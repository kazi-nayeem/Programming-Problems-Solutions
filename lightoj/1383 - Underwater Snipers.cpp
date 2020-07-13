//#include <bits/stdc++.h>

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MX 10005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

struct point
{
    ll x, y;
    bool operator < (const point &p) const
    {
        return y<p.y;
    }
};

point ca[MX];
point arr[MX];
int n, s;
ll d, k;

inline ll dist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool canpass(const ll &y)
{
    for(int i = 0; i < n; i++)
    {
        if(d < abs(y-arr[i].y)) return false;
        ll x = (ll) sqrt((ll) d*d - (y-arr[i].y)*(y-arr[i].y));
        ca[i].x = arr[i].x-x;
        ca[i].y = arr[i].x+x;
    }
    sort(ca,ca+n);
    int now = 1;
    ll pre = ca[0].y;
    for(int i = 1; i < n; i++)
    {
        if(pre < ca[i].x)
        {
            pre = ca[i].y;
            now++;
        }
        if(now>s) return false;
    }
    return now<=s;
}

ll func()
{
    ll res = k+100;

    /*for(ll i = k-d-5; i <= k+1; i++)
    {
        printf("%lld ", i);
        if(canpass(i))
            puts("YES");
        else
            puts("NO");
    }*/
    ll low = k-d-1;
    ll hi = k+10;
    ll mid;
    while(low <= hi)
    {
        //printf("%lld %lld\n", low, hi);
        mid = (low+hi)/2;
        if(canpass(mid))
        {
            hi = mid-1;
            res = min(res,mid);
        }
        else
            low = mid+1;
    }
    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %d %d %lld", &k, &n, &s, &d);
        for(int i = 0; i < n; i++)
            scanf("%lld %lld", &arr[i].x, &arr[i].y);
        printf("Case %d: ", te);
        if(!canpass(k))
        {
            puts("impossible");
            continue;
        }
        ll res = func();

        if(res > k)
            puts("impossible");
        else
            printf("%lld\n", k-res);
    }
    return 0;
}
