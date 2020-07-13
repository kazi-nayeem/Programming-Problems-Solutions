#include<stdio.h>
#include<math.h>

#define MAX 1000050LL
#define MAXP 78502

int almost[MAX];
int prime[MAXP];

void sieve(void );

int main()
{
    long long int te, a, b, i, j, k, n, root;
    sieve();
    scanf("%lld", &te);
    while(te--)
    {
        scanf("%lld %lld", &a, &b);

        root = sqrt(b)+1;
        n = 0;
        for(i = 0; prime[i] <= root; i++)
        {
            for(j = prime[i]*prime[i]; j <= b; j *= prime[i])
            {
                if(j >= a) n++;
            }
        }
        printf("%lld\n", n);
    }
    return 0;
}

void sieve(void )
{
    long long int n = 1, i, j, add;
    prime[0] = 2;
    for(i = 3; i < MAX; i+=2)
    {
        if(almost[i] == 0)
        {
            prime[n++] = i;
            add = i + i;
            for(j = i * i; j < MAX; j += add)
                almost[j] = 1;
        }
    }
    return;
}
