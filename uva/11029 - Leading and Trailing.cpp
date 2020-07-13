#include<cstdio>
#include<cmath>
using namespace std;

int n;

int bigmod(int p);

int main()
{
    int k, ti, te, logn;
    double logd;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &k);
        logn = logd = k * log10(n);
        logd -= logn;
        logn = 100 * pow(10,logd);
        printf("%03d...%03d\n", logn, bigmod(k));
    }
}

int bigmod(int p)
{
    if(p == 0) return 1;
    long long int big = bigmod(p/2);
    if(p&1)
        return (big*big*n) % 1000;
    return (big*big) % 1000;
}
