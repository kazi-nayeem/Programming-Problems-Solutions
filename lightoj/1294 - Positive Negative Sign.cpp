#include<cstdio>
using namespace std;

#define lli long long int

int main()
{
    int te, ti;
    lli n, m;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld%lld", &n, &m);
        printf("Case %d: %lld\n", te, n*m/2);
    }
    return 0;
}
