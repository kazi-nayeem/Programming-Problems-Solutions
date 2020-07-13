#include<stdio.h>
#include<math.h>

#define MAXF 1000001
#define MAXP 78499

int flag[MAXF];
long int prime[MAXP];
void sieve(void);

int main()
{
    sieve();
    long int n, k;
    long int i, j;
    int total;
    while(scanf("%ld", &n) == 1)
    {
        if(n == 0) break;
        if(flag[n] == 0)
        {
            printf("%ld : 1\n", n);
            continue;
        }
        k = n;
        total = 0;
        for(i = 0; prime[i] <= n; i++)
        {
            if(n % prime[i] == 0)
            {
                total++;
                do
                n /= prime[i];
                while(n % prime[i] == 0);
            }
        }
        printf("%ld : %d\n", k, total);
    }
    return 0;
}

void sieve(void)
{
    long int i, j, add;
    flag[0] = 1;
    flag[1] = 1;
    prime[0] = 2;
    long int k = 1;
    for(i = 4; i < MAXF; i+=2)
        flag[i] = 1;
    for(i = 3; i < MAXF; i+= 2)
    {
        if(flag[i] == 0)
        {
            prime[k++] = i;
            if(MAXF / i >= i)
            {
                add = i << 1;
                for(j = i * i; j < MAXF; j += add)
                    flag[j] = 1;
            }
        }
    }
    return;
}
