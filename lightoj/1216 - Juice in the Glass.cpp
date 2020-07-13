#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;

const double pi = acos(-1);

int main()
{
    double r1,r2,r3,h,p,x,v;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %lf %lf %lf %lf", &r1, &r2, &h, &p);
        //printf("r1 = %lf r2 = %lf h = %lf p = %lf\n", r1, r2, h, p);
        x = r2 * h / (r1-r2);
        r3 = r2 *(x+p) / x;
        //printf("%lf %lf\n", x, r3);
        v = pi * (((p+x)*r3*r3) - (x*r2*r2)) / 3;
        printf("Case %d: %.9lf\n", te, v);
    }
    return 0;
}
