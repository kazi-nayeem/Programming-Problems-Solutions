#include<stdio.h>

#define MAX 1000000

short int flag[MAX];

void sieve(void);

int main()
{
    sieve();
    long int n, a;
    while(scanf("%ld", &n) == 1 && (n != 0))
    {
        for(a = 3; a < n; a += 2)
            if((!flag[a]) && (!flag[n-a]))
            {
                printf("%ld = %ld + %ld\n", n, a, n - a);
                break;
            }
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 1, flag[1] = 1;
    long int i, j, k;
    for(i = 4; i <= MAX; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            k = MAX / i;
            for(j = i; j <= k ; j += 2)
                flag[i * j] = 1;
        }
    }
    return;
}
