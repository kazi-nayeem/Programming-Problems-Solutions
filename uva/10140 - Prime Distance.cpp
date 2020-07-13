#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;


#define MX 46355
#define MXP 4794
#define ll long long int

int prime[MXP];
int check[1000005];

void sieve(void)
{
    prime[0] = 2;
    int pos = 1;
    for(ll i = 3; i < MX; i+=2)
    {
        if(check[i] == 0)
        {
            prime[pos++] = i;
            for(ll j = i*i; j < MX; j+= i<<1)
                check[j] = 1;
        }
    }
}

int main()
{
    sieve();
    ll a, b;
    while(scanf("%lld%lld", &a, &b) == 2)
    {
        memset(check, 0, (sizeof (int))*(b-a+1));
        for(ll i = 0; (ll) prime[i]*prime[i] <= b && i < MXP; i++)
        {
            ll j = (ll) ((a+prime[i]-1)/prime[i])*prime[i];
            j = max((ll)prime[i]*prime[i],j);
            for(; j <= b; j += prime[i])
                check[j-a] = 1;
        }
        if(a == 1) check[0] = 1;
        int pos;
        for(ll i = 0; i <= b-a; i++)
        {
            pos = i;
            if(check[i] == 0)
                break;
        }
        int cont = 1, mi = 10000000, mx = -1, p, q;
        for(ll i = pos+1; i <= b-a; i++)
        {
            if(check[i] == 0)
            {
                if(i-pos<mi)
                {
                    p = pos;
                    mi = i-pos;
                }
                if(i-pos>mx)
                {
                    q = pos;
                    mx = i-pos;
                }
                cont++;
                pos = i;
            }
        }
        if(cont >= 2)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a+p,a+p+mi, a+q, a+q+mx);
        else
            printf("There are no adjacent primes.\n");
        //printf("Case %d: %d\n", te, cont);
    }
    return 0;
}
