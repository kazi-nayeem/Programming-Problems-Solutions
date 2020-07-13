#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int n, te, ti, pre, now, res;

    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        pre = 2;
        res = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &now);
            res += (int) ceil(double(now-pre)/5);
            pre = now;
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
