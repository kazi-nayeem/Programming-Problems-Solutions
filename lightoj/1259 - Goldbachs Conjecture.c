#include<stdio.h>
#include<math.h>

#define MAX 10000003
#define MAXP 664579

short int flag[MAX];
int prime[MAXP];

void sieve(void);

int main()
{
    sieve();
    long long int n, gold;
    int i, j;
    long long int time, test;
    scanf("%lld", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%lld", &n);
        gold = 0;
        j = n / 2;
        for(i = 0; prime[i] <= j; i++)
            if(!flag[n - prime[i]])
                gold++;
        printf("Case %lld: %lld\n", test, gold);
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 1, flag[1] = 1;

    register int i, j, k = 1, add, root = (int) sqrt(MAX);

    for(i = 4; i <= MAX; i += 2)
        flag[i] = 1;

    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            prime[k++] = i;

            if(root >= i)
            {
                add = i * 2;

                for(j = i * i; j < MAX ; j += add)
                    flag[j] = 1;
            }
        }
    }

    prime[0] = 2;
    return;
}

