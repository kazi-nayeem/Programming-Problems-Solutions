#include<cstdio>
#include<cmath>
//#include<iostream>
using namespace std;

const double pi = acos(-1);

inline double sqr(double a)
{
    return a*a;
}

inline int sqr(int a)
{
    return a*a;
}

inline double dis(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

inline double area(double r, double x, double y)
{
    double th = asin(y/sqrt(sqr(x)+sqr(y)));
    return th*sqr(r)-fabs(x*y);
}

int main()
{
    int te, ti;
    int x1, x2, y1, y2, r1, r2;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        printf("Case %d: ", te);

        if(r1 < r2)
        {
            r1 ^= r2 ^= r1 ^= r2;
        }
        int dist = sqr(x1-x2)+sqr(y1-y2);

        if(dist >= sqr(r1+r2))
        {
            puts("0.0");
            continue;
        }
        if(dist <= sqr(r1-r2))
        {
            printf("%.10lf\n", pi*sqr((double)r2));
            continue;
        }
        double d = dis(x1,y1,x2,y2);
        double x = sqr((double)r1)-sqr((double) r2)+sqr(d);
        x /= 2.0*d;
        double y = sqrt(sqr((double) r1)-sqr(x));
        //printf("X = %lf\n", x);
        double ans = area((double) r1, x, y);
        if(dist < sqr(x))
        {
            ans -= area((double) r2, x-d, y);
            ans += pi*r2*r2;
        }
        else
        {
            ans += area((double) r2, x-d, y);
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
