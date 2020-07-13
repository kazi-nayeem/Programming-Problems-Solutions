#include<stdio.h>

int main()
{
    int n, i;
    long long int fact;
    while(scanf("%d", &n) == 1)
    {
        fact = 1;
        for(i = 2; i <=  n; i++)
        {
            fact *= i;
            while(fact%10 == 0)
                fact /= 10;
            fact %= 1000000000;
        }
        printf("%5d -> %d\n", n, fact%10);
    }
    return 0;
}
