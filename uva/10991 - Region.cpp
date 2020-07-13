#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int te, ti;
    double r1, r2, r3, A, B, C, total, r11, r22, r33, r12, r23, r31;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lf%lf%lf", &r1, &r2, &r3);

        r11 = r1*r1,r22 = r2*r2, r33 = r3*r3;
        r12 = r1*r2, r23 = r2*r3, r31 = r3*r1;

        total = sqrt((r1+r2+r3)*r1*r2*r3);
        A = acos((r11+r31+r12-r23)/(r11+r31+r12+r23));
        B = acos((r22-r31+r12+r23)/(r22+r31+r12+r23));
        C = acos((r33+r31-r12+r23)/(r33+r31+r12+r23));

        total -= 0.5 * (A*r11+B*r22+C*r33);
        printf("%.6lf\n", total);
    }
    return 0;
}
