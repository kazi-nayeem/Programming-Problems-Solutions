//C headers
#include <stdio.h>
#include<cmath>
#include <algorithm>
using namespace std;

#define MX 50500
#define ll long long

struct point
{
    ll x, y;
};

bool operator < (const point &l, const point & r)
{
    return l.y<r.y || (l.y == r.y && l.x < r.x);
}

bool mult(point sp, point ep, point op)
{
    return (sp.x-op.x)*(ep.y - op.y) >=(ep.x-op.x)*(sp.y-op.y);
}

point pnt[MX];
point res[MX];

int graham(int n)
{
    int i,len,k = 0, top = 1;
    sort(pnt,pnt+n);
    res[0] = pnt[0];
    res[1] = pnt[1];
    res[2] = pnt[2];

    for(int i = 2; i < n; i++)
    {
        while(top && mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n-2];
    for(int i = n-3; i>=0;i--)
    {
        while(top!=len && mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    return top;
}

ll sqr(ll a)
{
    return a*a;
}

double dis(point a, point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

const double pi = acos(-1);

int main()
{
    int n, d, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &d);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &pnt[i].x, &pnt[i].y);
        }
        int len = graham(n);
        double ans = 0.0;
        for(int i = 1; i <= len; i++)
        {
            ans += dis(res[i],res[i-1]);
        }
        printf("Case %d: %.10lf\n", te, ans+2.0*d*pi);
    }

    return 0;
}
