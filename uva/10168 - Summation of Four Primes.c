#include<stdio.h>
#include<math.h>

#define MAX 10000000
#define MAXP 664579

short int flag[MAX];
int prime[MAXP];

void sieve(void);

int main()
{
    sieve();
    long int n, a;
    while(scanf("%ld", &n) == 1)
    {
        if(n < 8)
        {
            printf("Impossible.\n");
            continue;
        }
        if(n & 1)
        {
            printf("2 3 ");
            n -= 5;
        }
        else
        {
            printf("2 2 ");
            n -= 4;
        }

        for(a = 0; a < MAXP; a++)
            if((!flag[n-prime[a]]))
            {
                printf("%ld %ld\n", prime[a], n - prime[a]);
                break;
            }
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 1, flag[1] = 1;
    long int i, j, k = 1, ad;
    prime[0] = 2;
    int root = sqrt(MAX) + 1;

    for(i = 4; i < MAX; i+= 2)
        flag[i] = 1;

    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            prime[k++] = i;
            if(i > root) continue;
            ad = i + i;
            for(j = i*i; j < MAX ; j += ad)
                flag[j] = 1;
        }
    }
    return;
}
