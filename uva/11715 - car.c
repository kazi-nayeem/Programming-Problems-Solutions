#include<stdio.h>
#include<math.h>

int main()
{
    int test, time = 0;
    double u, v, a, t, s;
    while(scanf(" %d", &test) == 1)
    {
        if(test == 0) break;
        switch(test)
        {
            case 1:
                    scanf(" %lf %lf %lf", &u, &v, &t);
                    s = (( u + v ) / 2) * t;
                    a = (v - u) / t;
                    printf("Case %d: %.3lf %.3lf\n", ++time, s, a);
                    break;
            case 2:
                    scanf(" %lf %lf %lf", &u, &v, &a);
                    t = (v - u) / a;
                    s = (( u + v ) / 2) * t;
                    printf("Case %d: %.3lf %.3lf\n", ++time, s, t);
                    break;
            case 3:
                    scanf(" %lf %lf %lf", &u, &a, &s);
                    v = sqrt((u * u) + (2 * a * s));
                    t = (v - u) / a;
                    printf("Case %d: %.3lf %.3lf\n", ++time, v, t);
                    break;
            case 4:
                    scanf(" %lf %lf %lf", &v, &a, &s);
                    u = sqrt((v * v) - (2 * a * s));
                    t = (v - u) / a;
                    printf("Case %d: %.3lf %.3lf\n", ++time, u, t);
                    break;
        }
    }
    return 0;
}
