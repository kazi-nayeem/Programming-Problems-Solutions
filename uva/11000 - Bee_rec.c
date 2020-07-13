#include<stdio.h>

long long int fibo(int n);

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == -1) break;
        printf("%lld %lld\n", fibo(n+1) - 1, fibo(n) + fibo(n+1) - 1);
    }
    return 0;
}

long long int fibo(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    return fibo(n - 1) + fibo(n -2);
}
