#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int te, ti, a, b;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d : %d", &a, &b);
        double x, s;
        s = sqrt((double)a*a+b*b)*atan((double) b/a);
        s += a;
        x = 200/s;
        printf("Case %d: %.10lf %.10lf\n", te, a*x, b*x);
    }
    return 0;
}
