#include<stdio.h>

#define ll unsigned long long
#define MX 3000005
//#define MX 30

int phi[MX+5];
ll lcmsum[MX+5];
ll sum_of_relative_prime[MX+5];

void func()
{
    ll i,j,k;
    for( i = 1; i < MX; i++)
        phi[i] = i;
    for(i = 2; i < MX; i+=2) phi[i]>>=1;
    for(i = 3; i < MX; i+=2)
    {
        if(phi[i] == i)
        {
            phi[i]--;
            for(j = i+i; j < MX; j += i)
                phi[j] -= phi[j]/i;
        }
        sum_of_relative_prime[i] = lcmsum[i] = (ll) (i*phi[i])>>1;
    }
    for(i = 2; i < MX; i+=2) sum_of_relative_prime[i] = lcmsum[i] = (ll) (i*phi[i])>>1;
    for(i = 2; i < MX; i++)
    {
        for(j = i<<1, k = 2; j < MX; j+=i, k++)
        {
            lcmsum[j] += sum_of_relative_prime[k];
        }
        lcmsum[i] = (ll) lcmsum[i-1]+((ll)lcmsum[i]*i);
    }
    return;
}

int main()
{
    func();
    int ti, te = 1, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        printf("Case %d: %llu\n", te++, lcmsum[n]);
    }
    return 0;
}
