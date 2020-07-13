#include<stdio.h>

#define MAXF 100000100LLU

short int flag[MAXF];

void sieve(void);

int main()
{
    sieve();
    unsigned long long int n;
    unsigned long long int i;
    while(scanf("%llu", &n) == 1)
    {
        if(n < 4)
            printf("%llu is not the sum of two primes!\n", n);
        else if(n & 1)
        {
            if(n == 3)
                printf("3 is the sum of 1 and 2.\n");
            else if(flag[n-2] == 0)
                printf("%llu is the sum of 2 and %llu.\n", n, n-2);
            else
                printf("%llu is not the sum of two primes!\n", n);
        }
        else
        {
            i = n / 2;
            for(i--; i>1;i--)
            {
                if(flag[i] == 0)
                {
                    if(flag[n-i] == 0)
                    break;
                }
            }
            if(i>1)
                printf("%llu is the sum of %llu and %llu.\n", n, i, n - i);
            else
                printf("%llu is not the sum of two primes!\n", n);
        }
    }
    return 0;
}

void sieve(void)
{
    unsigned long long int i, j, k;
    flag[1] = 1;
    flag[0] = 1;
    for(i = 4; i < MAXF; i+=2)
        flag[i] = 1;
    for(i = 3; i < MAXF; i++)
    {
        if(flag[i] == 0)
        {
            if(MAXF / i >= i)
            {
                k = i + i;
                for(j = i * i; j < MAXF; j += k)
                    flag[j] = 1;
            }
        }
    }
    return;
}
