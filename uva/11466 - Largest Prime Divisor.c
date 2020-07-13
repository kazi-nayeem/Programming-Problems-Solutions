#include<stdio.h>

#define MAXF 31622780
#define MAXP 1951959

long long int primenumber[MAXP];
int flag[MAXF];

void sieve(void);

int main()
{
    sieve();
    long long int n, large, maine;
    register long int i;
    while(scanf("%lld", &n) == 1 && (n != 0))
    {
        maine = n;
        large = 0;
        for(i = 0; i < MAXP && primenumber[i] <= n;)
            {
                if(n % primenumber[i] == 0)
                {
                    n /= primenumber[i];
                    large = primenumber[i];
                }
                else
                    i++;
            }

        if(large == maine || (large == 0))
            printf("-1\n");
        else
        {
            if(n>1)
                printf("%lld\n", n);
            else
                printf("%lld\n", large);
        }
    }
    return 0;
}


void sieve(void)
{
    register long long int i, j, k = 1, add;
    primenumber[0] = 2;
    for(i = 4; i < MAXF; i+=2)
        flag[i] = 1;
    for(i = 3; i < MAXF; i += 2)
    {
        if(!flag[i])
        {
            primenumber[k++] = i;
            if(MAXF / i >= i)
            {
                add = i * 2;
                for(j = i * i; j < MAXF; j += add)
                    flag[j] = 1;
            }
        }
    }
    return;
}
