#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    double l, w, x1, x2, sq, area;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lf%lf", &l, &w);
        sq = sqrt(((l+w)*(l+w))-(3*l*w));
        x1 = (l+w-sq)/6;
        x2 = (l+w+sq)/6;
        if(((24*x1)-(4*(l+w))) < 0)
            area = (l-(2*x1))*(w-(2*x1))*x1;
        else
            area = (l-(2*x2))*(w-(2*x2))*x2;
        printf("Case %d: %.8lf\n", te, area);
    }
    return 0;
}
