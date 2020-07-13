#include<stdio.h>
#include<math.h>

int main()
{
    int te, ti;
    double a, b, c, d, s, h, area, tem;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        if(a < c)
        {
            tem = a;
            a = c;
            c = tem;
        }
        s = (a+b+d-c)/2;
        h = 2*sqrt(s*(s-a+c)*(s-b)*(s-d));
        h /= (a-c);
        area = 0.5 * h * (a+c);
        printf("Case %d: %.8lf\n", te, area);
    }
    return 0;
}
