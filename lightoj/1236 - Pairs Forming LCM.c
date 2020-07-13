#include<stdio.h>
#include<string.h>
#include<math.h>

#define MX 10000500
#define MXP 664604
#define ll long long

char flag[(MX>>3)+5];
int prime[MXP];

int check(int num)
{
    return (flag[num>>3]>>(num& 0b111))&1;
}

void input(int num)
{
    flag[num>>3] |= 1<<(num& 0b111);
    return;
}

void sieve(void )
{
    ll i, j;
    prime[0] = 2;
    int pos = 1;
    for(i = 3; i < MX; i+=2)
    {
        if(check(i)) continue;
        prime[pos++] = i;
        for(j = i*i; j < MX; j+= i<<1)
            input(j);
    }
    return;
}

int main()
{
    sieve();
    int te, ti, root, tk, i;
    ll n, res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        res = 1;
        root = sqrt(n);
        for(i = 0; i < MXP && root >= prime[i]; i++)
        {
            tk = 0;
            while(n%prime[i] == 0)
            {
                tk++;
                n /= prime[i];
            }
            if(tk == 0) continue;
            res *= (tk<<1) + 1;
            root = sqrt(n);
        }
        if(n>1) res *= 3;
        printf("Case %d: %lld\n", te, (res+1ll)>>1);
    }
    return 0;
}
