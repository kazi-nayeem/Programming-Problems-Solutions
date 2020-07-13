#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    int te, ti, i;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        for(i = 0; i < 32; i++)
            if((n>>i)&1) break;
        for(int k = 0; i < 32; i++,k++)
        {
            if(((n>>i)&1) && ((n>>(i+1))&1))
            {
                n = n & (~(1<<i));
                n = n | (1<<k);
                continue;
            }
            if(((n>>i)&1)) continue;
            n = n & (~(1<<(i-1)));
            n = n | (1<<i);
            break;
        }
        printf("Case %d: %lld\n", te, n);
    }
    return 0;
}
