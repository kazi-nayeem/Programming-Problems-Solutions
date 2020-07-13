#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int te, ti, n, flag, tem;
    int x1[3], x2[3], res1[3], res2[3];
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        flag = 0;
        scanf("%d", &n);
        for(int i = 0; i < 3; i++)
            scanf("%d", &res1[i]);
        for(int i = 0; i < 3; i++)
        {
            scanf("%d", &res2[i]);
            if(res1[i] > res2[i])
            {
                tem = res1[i];
                res1[i] = res2[i];
                res2[i] = tem;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int i = 0; i < 3; i++)
                scanf("%d", &x1[i]);
            for(int i = 0; i < 3; i++)
            {
                scanf("%d", &x2[i]);
                if(x1[i] > x2[i])
                {
                    tem = x1[i];
                    x1[i] = x2[i];
                    x2[i] = tem;
                }
                if(x1[i] >= res1[i])
                {
                    if(x1[i] >= res2[i]) flag = 1;
                    else res1[i] = x1[i];
                }
                if(x2[i] <= res2[i])
                {
                    if(x2[i] <= res1[i]) flag = 1;
                    else res2[i] = x2[i];
                }
            }
        }

        if(flag)
            printf("Case %d: 0\n", te);
        else
        {
            long long int total = 1;
            for(int i = 0; i < 3; i++)
                total *= abs(res1[i]-res2[i]);
            printf("Case %d: %lld\n", te, total);
        }
    }
    return 0;
}
