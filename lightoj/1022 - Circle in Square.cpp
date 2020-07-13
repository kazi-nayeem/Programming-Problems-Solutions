#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int time, test;
    double r, area, total;
    double pi = 2 * acos(0.0);
    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%lf", &r);
        total = 4 * r * r;
        area = pi * r * r;
        printf("Case %d: %.2lf\n", test, total - area);
    }
    return 0;
}
