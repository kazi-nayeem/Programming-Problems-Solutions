#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define MX 100000500
#define MXP 5761482

char flag[MX/8+1];
unsigned int prime[MXP];
unsigned int multi[MXP];

void setbit(int i)
{
    flag[i>>3] = flag[i>>3] | (1<<(i&7));
}
int info(int i)
{
    return (flag[i>>3]>>(i&7))&1;
}

void sieve(void)
{
    register int pos = 1, ad, i, j;
    prime[0] = 2;
    multi[0] = 2;

    for( i = 3; i < MX; i+=2)
    {
        if(info(i) == 0)
        {
            //if(i < 100)
            //printf("%d\n", i);
            prime[pos] = i;
            multi[pos] = multi[pos-1]*i;
            pos++;
            ad = i+i;
            if(MX/i>i)
            for(j = i*i; j < MX; j+=ad)
                setbit(j);
        }
    }
    //printf("%d\n", pos);
    //for(i = 0; i < 100; i++)
      // printf("%u\n", prime[i]);
}

int main()
{
    sieve();
    unsigned int res;
    unsigned int te, ti, n;
    scanf("%u", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%u", &n);
        res = 1;
        unsigned int sq = sqrt(n);
        unsigned int *p = lower_bound(prime,prime+MXP,n);
        //printf("%u", prime[MXP-1]);
        unsigned int len = p - prime;
        if(prime[len] != n) len--;
        res = multi[len];
        //printf("res = %u   %u\n", res, prime[len]);
        for(int i = 0; i < MXP && prime[i] <= sq; i++)
        {
            //printf("    %u\n", prime[i]);
            for(long long int tem = prime[i]*prime[i]; tem <= n; tem *= prime[i], res *= prime[i]);
        }
        printf("Case %u: %u\n", te, res);
    }
    return 0;
}
