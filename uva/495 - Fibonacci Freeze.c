#include<stdio.h>

#define MAX 2000

void fibonacci(int n);

int fibo1[MAX], fibo2[MAX];

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            printf("The Fibonacci number for 0 is 0\n");
        else if(n < 3)
            printf("The Fibonacci number for %d is 1\n", n);
        else if(n < 227)
        {
            printf("The Fibonacci number for %d is ", n);
            fibonacci(n);
        }
        else
        {
            printf("The Fibonacci number for %d is\n", n);
            fibonacci(n);
        }
    }
    return 0;
}

void fibonacci(int n)
{
    int i, j, rem, total;
    fibo1[MAX - 1] = 1;
    fibo2[MAX - 1] = 1;
    for(j = 3; j <= n; j++)
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
    }
    rem = 0;
    for(i = 0; i < MAX; i++)
    {
        if(rem == 1 || fibo2[i] != 0)
        {
            rem = 1;
            printf("%d", fibo2[i]);
        }
        fibo2[i] = 0;
        fibo1[i] = 0;
    }
    putchar('\n');
    return ;
}
