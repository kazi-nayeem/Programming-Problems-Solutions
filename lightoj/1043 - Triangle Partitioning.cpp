#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double a, b, c, d;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        d = sqrt(d/(1+d));
        printf("Case %d: %.10lf\n", te, a*d);
    }
    return 0;
}
