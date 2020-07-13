#include<cstdio>
using namespace std;

int main()
{
    int ti, te, ax, bx, cx, dx, ay, by, cy, dy, area;

    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

        dx = ax+cx-bx;
        dy = ay+cy-by;

        area = ax*by + bx*cy + cx*dy + dx*ay - ax*dy - dx*cy - cx*by - bx * ay;
        if(area < 0) area = 0 - area;
        area /= 2;
        printf("Case %d: %d %d %d\n", te, dx, dy, area);
    }
    return 0;
}
