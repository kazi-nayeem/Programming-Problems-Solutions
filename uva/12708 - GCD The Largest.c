#include<stdio.h>

int main()
{
    long long int n;
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld", &n);
        printf("%lld\n", n >> 1);
    }
    return 0;
}
