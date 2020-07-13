#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define ll long long int

int main()
{
    int te, ti;
    ll sq, n, res, a, b;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        sq = sqrt(n);
        res = 0;
        for(ll i = 2; i <= sq; i++)
        {
            res += (ll)(((n/i)-1)*i);
            if(i*i == n) continue;
            a = n/i;
            if(a <= sq) continue;
            b = n/(i+1);
            if(b < sq)
                b = sq;
            a = (a+1)*a/2;
            b = (b+1)*b/2;
            res += (a-b)*(i-1);
        }
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
