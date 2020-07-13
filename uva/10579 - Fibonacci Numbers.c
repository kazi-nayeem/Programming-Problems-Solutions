#include<stdio.h>


#define MAX 1005
#define MAXF 4795

void fibonacci(void);

struct {
            char fibonaccinum[MAX];
        } fibona[MAXF];

int fibo1[MAX], fibo2[MAX];

int main()
{
    fibona[0].fibonaccinum[0] = '0';
    fibona[0].fibonaccinum[1] = '\0';
    fibona[1].fibonaccinum[0] = '1';
    fibona[1].fibonaccinum[1] = '\0';
    fibona[2].fibonaccinum[0] = '1';
    fibona[2].fibonaccinum[1] = '\0';
    fibonacci();
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("%s\n", fibona[n].fibonaccinum);
    }
    return 0;
}

void fibonacci(void)
{
    int i, j, rem, total, k;
    fibo1[MAX - 1] = 1;
    fibo2[MAX - 1] = 1;
    for(j = 3; j < MAXF; j++)
    {
        rem = 0;
        for(i = MAX - 1; i > 0; i--)
        {
            total = fibo1[i] + fibo2[i] + rem;
            rem = 0;
            if(total > 9)
            {
                total -= 10;
                rem = 1;
            }
            fibo1[i] = fibo2[i];
            fibo2[i] = total;
        }
        rem = 0;
        for(i = 0, k = 0; i < MAX; i++)
        {
            if(rem == 1 || fibo2[i] != 0)
            {
                rem = 1;
                fibona[j].fibonaccinum[k++] = fibo2[i] + 48;
            }
        }
        fibona[j].fibonaccinum[k] = '\0';
    }
    return;
}


