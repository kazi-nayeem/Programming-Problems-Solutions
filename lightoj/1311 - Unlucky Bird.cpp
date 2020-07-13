#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int te, ti;
    double v1, v2, v3, a1, a2, t1, t2, s;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &a1, &a2);
        t1 = v1/a1;
        t2 = v2/a2;
        s = t1*(v1-0.5*t1*a1)+t2*(v2-0.5*t2*a2);
        printf("Case %d: %.10lf %.10lf\n", te, s, max(t1,t2)*v3);
    }
    return 0;
}
