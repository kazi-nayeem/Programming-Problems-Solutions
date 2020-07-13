#include<stdio.h>

#define MAXF 18409202
#define MAXT 100001
typedef struct {
                    long int a;
                    long int b;
} twinprime;

twinprime prime[MAXT];
int flag[MAXF];

long int t;

void sieve(void);

int main()
{
    long int n;
    sieve();
    while(scanf("%ld", &n) == 1)
        printf("(%ld, %ld)\n", prime[n].a, prime[n].b);
    return 0;
}

void sieve(void)
{
    long int i, j, add;
    flag[0] = 1;
    flag[1] = 1;
    for(i = 4; i < MAXF; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAXF; i += 2)
    {
        if(!flag[i])
        {
            if(!flag[i-2])
            {
                prime[++t].a = i - 2;
                prime[t].b = i;
            }
            if(MAXF / i >= i)
            {
                for(add = i << 1, j = i * i; j < MAXF; j += add)
                    flag[j] = 1;
            }
        }
    }
    return;
}
