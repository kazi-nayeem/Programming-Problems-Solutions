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
const double pi = acos(-1);

ll sqll(ll a)
{
    return a*a;
}

ll disll(pll a)
{
    return sqll(a.first)+sqll(a.second);
}

double disdl(pll a)
{
    return sqrt(sqll(a.first)+sqll(a.second));
}

pll arr[MX];
ll radius[MX];

vector<pair<double,double> >res;

void add(double d1, double d2)
{
    if(d1 > 2*pi) d1 -= 2*pi;
    if(d2 > 2*pi) d2 -= 2*pi;
    if(d2 < d1)
    {
        res.push_back(make_pair(0,d2));
        res.push_back(make_pair(d1,2*pi));
    }
    else
    {
        res.push_back(make_pair(d1,d2));
    }
}

void inside(pll p, ll r)
{
    double x = disdl(p);
    double a = (double)(disll(p)-sqll(r))/dis;
    double b = sqrt(a*x-a*a);
    double d1 = atan(b/a);
    double d2 = -d1;
    double sf = 0.0;
    if(p.first != 0)
        sf = atan((double) p.second/p.first);
    else if(p.second >= 0)
        sf = pi/2;
    else
        sf = pi*1.5;
    d1 += sf;
    d2 += sf;
    add(d1,d2);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll x, y, v, t, n;
    scanf("%lld%lld%lld%lld", &x, &y, &v, &t);
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld", &arr[i].first, &arr[i].second, &radius[i]);
        arr[i].first -= x;
        arr[i].second -= y;
    }
    ll r = v*t;
    for(int i = 0; i < n; i++)
    {
        if(disll(arr[i]) <= sqll(radius[i]))
        {
            res.push_back(make_pair(0.0, 2*pi));
            continue;
        }
        double dist = disdl(arr[i]);
        if(dist-radius[i] > r) continue;
        if(dist+radius[i] <= r)
        {
            inside(arr[i], radius[i]);
            continue;
        }
    }
    return 0;
}


