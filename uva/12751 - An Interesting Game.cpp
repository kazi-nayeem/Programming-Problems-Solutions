#include<cstdio>
using namespace std;

typedef long long int ll;


int main()
{
    int te, ti;
    ll res, n, x, k;
    scanf("%d", &ti);

    for(te=1; te <= ti; te++)
    {
        scanf("%lld%lld%lld", &n, &k, &x);
        k = x+k-1;
        res = ((n*(n+1))+(x*(x-1))-(k*(k+1)))/2;
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}

