#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;


#define MX 46355
#define MXP 4794
#define ll long long int

int prime[MXP];
int check[100005];

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
    int te, ti;
    ll a, b;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld%lld", &a, &b);
        memset(check, 0, (sizeof (int))*(b-a+1));
        for(ll i = 0; (ll) prime[i]*prime[i] <= b && i < MXP; i++)
        {
            ll j = (ll) ((a+prime[i]-1)/prime[i])*prime[i];
            j = max((ll)prime[i]*prime[i],j);
            for(; j <= b; j += prime[i])
                check[j-a] = 1;
        }
        int cont = 0;
        for(ll i = 0; i <= b-a; i++)
            if(check[i] == 0)
                cont++;
        if(a == 1) cont--;
        printf("Case %d: %d\n", te, cont);
    }
    return 0;
}
