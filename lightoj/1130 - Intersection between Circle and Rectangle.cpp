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
const double PI = acos(-1);


struct ipoint
{
    ll x, y;
    ipoint() {}
    ipoint(ll a, ll b)
    {
        x = a;
        y = b;
    }
};
struct fpoint
{
    double x, y;
    fpoint(double a, double b)
    {
        x = a;
        y = b;
    }
};

ll llsqr(ll a)
{
    return a*a;
}

ll dissqr(ipoint a, ipoint b)
{
    return llsqr(a.x-b.x)+llsqr(a.y-b.y);
}

double fsqr(double a)
{
    return a*a;
}

double dis(fpoint a, fpoint b)
{
    return sqrt(fsqr(a.x-b.x)+fsqr(a.y-b.y));
}

bool isleft(fpoint a, fpoint b, fpoint c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)>=0.0;
}

struct icircle
{
    ipoint center;
    ll r;
};

struct irectangle
{
    ipoint a, b;
};

double arc_area(icircle c,fpoint a,fpoint b)
{
    double di = dis(a,b)/2;
    double th = asin( di / c.r );
    double l = c.r*cos(th);
    double area = th*llsqr(c.r)-di*l;
    if(isleft(a,b,fpoint(c.center.x,c.center.y))) return area;
    return PI*llsqr(c.r)-area;
}

double upper_area(icircle cm, ipoint p)
{
    icircle c = cm;
    c.center.x -= p.x;
    c.center.y -= p.y;
    if(c.center.x+c.r <= 0 || c.center.y+c.r <= 0) return 0.0;
    if(c.center.x-c.r >= 0 && c.center.y-c.r >= 0) return PI*c.r*c.r;
    printf("%lld %lld\n", c.center.x, c.center.y);
    printf("%lld\n", dissqr(c.center,ipoint(0,0)));
    if(dissqr(c.center,ipoint(0,0)) <= llsqr(c.r))
    {
        double x = sqrt(llsqr(c.r)-llsqr(c.center.y))+c.center.x;
        double y = sqrt(llsqr(c.r)-llsqr(c.center.x))+c.center.y;
        printf("ok");
        return 0.5*x*y+arc_area(c,fpoint(x,0.0),fpoint(0.0,y));
    }
    if(c.center.x>=0 && c.center.y>=0)
    //printf("%lf %lf\n", xx, yy);
    double area = PI*llsqr(c.r);
    //printf("area %lf\n", area);
    if(c.center.y-c.r < 0)
    {
        double xx = sqrt(llsqr(c.r)-llsqr(c.center.y));
        area -= arc_area(c,fpoint(c.center.x-xx,0.0),fpoint(c.center.x+xx,0.0));
    }
    if(c.center.x-c.r < 0)
    {
        double yy = sqrt(llsqr(c.r)-llsqr(c.center.x));
        area -= arc_area(c,fpoint(0.0,c.center.y+yy),fpoint(0.0,c.center.y-yy));
    }
    return area;
}

double intersection_area(icircle c, irectangle rec)
{
    double tem;
    double area = tem = upper_area(c,rec.a);
    printf("%lf\n", tem);
    area += tem = upper_area(c,rec.b);
    printf("%lf\n", tem);
    area -= tem = upper_area(c,ipoint(rec.a.x,rec.b.y));
    printf("%lf\n", tem);
    area -= tem = upper_area(c,ipoint(rec.b.x,rec.a.y));
    printf("%lf\n", tem);
    return area;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti;
    icircle c;
    irectangle rec;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld %lld", &c.center.x, &c.center.y, &c.r);
        scanf("%lld %lld %lld %lld", &rec.a.x, &rec.a.y, &rec.b.x, &rec.b.y);
        printf("Case %d: %.12lf\n", te, intersection_area(c,rec));
    }
    return 0;
}


