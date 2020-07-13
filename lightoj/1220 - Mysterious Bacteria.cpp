#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int ti, te, k;
    long long int n;
    double tem;
    double tm;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        if(n < 0)
        {
            tem = (double) (-n);
            for(k = 31; k > 1; k-=2)
            {
                tm = (double) pow(tem, (double) 1/k);
                if(tem == pow(ceil(tm), k) || tem == pow(floor(tm), k))
                    break;
            }
        }
        else
        {
            for(k = 32; k > 1; k--)
            {
                tm = pow(n, (double) 1/k);
                if(n == pow(ceil(tm), k) || n == pow(floor(tm), k))
                    break;
            }
        }
        printf("Case %d: %d\n", te, k);
    }
    return 0;
}
