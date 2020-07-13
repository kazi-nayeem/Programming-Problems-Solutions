#include<stdio.h>

int main()
{
    long long int n;
    while(scanf("%lld", &n) == 1)
    {
        if(n <= 0) break;
        if(n > 1)
            printf("%lld%%\n", n * 25);
        else
            printf("0%%\n");
    }
    return 0;
}
