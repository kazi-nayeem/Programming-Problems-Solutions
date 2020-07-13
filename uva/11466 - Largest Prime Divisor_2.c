#include<stdio.h>
#include<math.h>

#define MAXF 31622780

int flag[MAXF];

void sieve(void);

int main()
{
    sieve();
    printf("ok\n");
    long long int n, large, maine;
    register long int i;
    while(scanf("%lld", &n) == 1 && (n != 0))
    {

    }
    return 0;
}


void sieve(void)
{
    register long long int i, j, k = 1, add, root = MAXF>>1;
    for(i = 4; i < MAXF; i+=2)
        flag[i] = 2;
    for(i = 3; i <= root; i += 2)
    {
        if(flag[i] == 0)
        {
            flag[i] = -1;
            for(j = i << 1; j < MAXF; j += i)
                flag[j] = i;
        }
    }
    return;
}

