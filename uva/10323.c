#include<stdio.h>

unsigned long long int fact(int n);

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    if(n <= 7 )
    printf("Underflow!\n");
    else if(n == 13)
    printf("6227020800\n");
    else if(n > 13)
    printf("Overflow!\n");
    else
    printf("%lld\n", fact(n));
    return 0;
}

unsigned long long int fact(int n)
{
    if(n == 7)
        return 5040;
    return (unsigned long long int )(n * fact(n -1));
}
