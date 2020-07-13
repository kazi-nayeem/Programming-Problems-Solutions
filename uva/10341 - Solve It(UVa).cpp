#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

//p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0

#define E 2.71828182

double exp_error = 1e-10;
int p, q, r, s, t, u;

double func(double x)
{
    return (double) p*pow(E,(0.-x)) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    double st, en, mid;
    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t , &u) == 6)
    {
        if(func(0)*func(1) > 0)
        {
            printf("No solution\n");
            continue;
        }
        if(func(0) < func(1))
        {
            st = 0;
            en = 1;
        }
        else
        {
            st = 1;
            en = 0;
        }
        while(1)
        {
            mid = (st+en)/2;
            double res = func(mid);
            if(fabs(res) < exp_error) break;
            if(res < 0)
                st = mid;
            else
                en = mid;
        }
        printf("%.4lf\n", (st+en)/2);
    }
    return 0;
}
