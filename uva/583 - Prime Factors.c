#include<stdio.h>

#define MAXF 46350
#define MAXP 4793

#define printfactor(n) { \
                            for(i = 0; i < MAXP && n > 1; ++i) \
                                    if(n % prime[i] == 0) \
                                            break; \
                            if(i < MAXP) \
                                { \
                                    printf("%ld", prime[i]); \
                                    n /= prime[i];\
                                } \
                            else \
                            { \
                                printf("%d", n); \
                                n = 1; \
                            } \
                            for(; n > 1 && i < MAXP; ++i) \
                            { \
                                while(n % prime[i] == 0) \
                                { \
                                    printf(" x %ld", prime[i]); \
                                    n /= prime[i]; \
                                } \
                            } \
                            if(n > 1) \
                                printf(" x %ld", n); \
                            printf("\n"); \
                        }

int flag[MAXF];
long int prime[MAXP];

void sieve(void);

int main()
{
    sieve();
    long int i, n;
    while(scanf("%ld", &n) == 1 && (n != 0))
    {
        printf("%ld = ", n);
        if(n == 1)
            printf("1\n");
        else if(n < 0)
        {
            if(n == -1)
                printf("-1\n");
            else
            {
                printf("-1 x ");
                n = (-n);
                printfactor(n);
            }
        }
        else
            printfactor(n);
    }
    return 0;
}

void sieve(void)
{
    int i, j, k;
    int p = 1;
    prime[0] = 2;
    for(i = 4; i <= MAXF; i += 2)
        flag[i] = 1;
    for(i = 3; i <= MAXF ; i += 2)
    {
        if(!flag[i])
        {
            prime[p++] = i;
            k = MAXF / i;
            for(j = i; j <= k; j += 2)
                flag[i * j] = 1;
        }
    }
    return;
}
