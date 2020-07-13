#include<stdio.h>
#include<math.h>

int main()
{
    double pi = acos(-1);
    double s;
    double angla;
    char ch[5];
    while(scanf("%lf%lf%s", &s, &angla, ch) == 3)
    {
        s += 6440;
        if(ch[0] == 'm')
            angla /= 60;
        if(angla > 180)
            angla = 360 - angla;
        angla = pi * angla / 180;
        printf("%.6lf %.6lf\n", angla * s, 2 * s * sin(angla/2));
    }
    return 0;
}
