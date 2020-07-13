#include<cstdio>
using namespace std;

int main()
{
    int te = 1, ti, n, m, k;
    double pro;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d%d%d%lf", &n, &m, &k, &pro);
        double ans = (double) n*k*pro;
        printf("Case %d: %.10lf\n", te++, ans);
    }
    return 0;
}
