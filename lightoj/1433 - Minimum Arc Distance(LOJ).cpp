#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double ax, ay, bx, by, ox, oy, teta, res, r, k;
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &ox, &oy, &ax, &ay, &bx, &by);
        r = sqrt(((oy - ay)*(oy - ay))+((ox-ax)*(ox-ax)));
        k = 0.5*sqrt(((by - ay)*(by - ay))+((bx-ax)*(bx-ax)));
        teta = 2 * asin(k/r);
        res = r*teta;
        printf("Case %d: %.9lf\n", te, abs(res));
    }
    return 0;
}
