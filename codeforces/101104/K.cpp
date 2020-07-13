//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct point
{
    ll a, b;
    point() {}
    point(ll c, ll d)
    {
        ll gc = __gcd(c,d);
        c /= gc;
        d /= gc;
        a = c;
        b = d;
    }
    bool operator < (const point & p) const
    {
        //printf("comp %lld %lld %lld %lld\n", a, b, p.a, p.b);
        return a*p.b<b*p.a;
    }
};

struct line
{
    point a, b;
    bool operator < (const line & p) const
    {
        return a<p.a;
    }
};

line arr[MX];
bool flag[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, n;
    ll x, y, x1, y1;
    scanf("%d", &ti);
    while(ti--)
    {
        memset(flag,0,sizeof flag);
        scanf("%d", &n);
        scanf("%I64d %I64d", &x, &y);
        for(int i = 0; i < n; i++)
        {
            scanf("%I64d %I64d", &x1, &y1);
            arr[i].a = point((x1*(y-y1))-(y1*(x-x1)),y-y1);
            scanf("%I64d %I64d", &x1, &y1);
            arr[i].b = point((x1*(y-y1))-(y1*(x-x1)),y-y1);
            if(arr[i].b < arr[i].a)
            {
                point a = arr[i].a;
                arr[i].a = arr[i].b;
                arr[i].b = a;
            }
        }
        if(n == 0)
        {
            printf("1\n");
            continue;
        }
        if(n == 1)
        {
            printf("2\n");
            continue;
        }
        /*for(int i = 0; i < n; i++)
        {
            puts("---------");
            printf("%lld %lld\n", arr[i].a.a, arr[i].a.b);
            printf("%lld %lld\n", arr[i].b.a, arr[i].b.b);
        }*/
        for(int i = 0; i < n; i++)
        {
            /*puts(">>>>>>>>>>>>>>>");
            printf("%lld %lld\n", arr[i].a.a, arr[i].a.b);
            printf("%lld %lld\n", arr[i].b.a, arr[i].b.b);*/
            if(flag[i]) continue;
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(flag[j]) continue;
                if(arr[j].b < arr[i].a || arr[i].b < arr[j].a) continue;
                //printf("update %d %d\n", i, j);
                arr[i].a = min(arr[i].a,arr[j].a);
                arr[i].b = max(arr[i].b,arr[j].b);
                i--;
                flag[j] = true;
                break;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            if(!flag[i]) res++;
        printf("%d\n", res+1);
    }
    return 0;
}

/**
2
3
50 60
55 45 30 35
64 39 92 18
20 30 40 16
2
-10 50
-10 1 10 11
-10 11 10 1
*/
