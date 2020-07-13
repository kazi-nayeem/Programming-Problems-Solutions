#include<stdio.h>
#include<string.h>

int main()
{
    double total;
    long int n, r;
    long int i;
    char str[105];
    while(scanf("%ld%ld", &n, &r) == 2)
    {
        if(r > n / 2)
            r  = n - r;
        for(total = i = 1; i <= r; i++, n--)
            total = total * n / i;
        sprintf(str,"%.0lf", total);
        printf("%d\n", strlen(str));
    }
    return 0;
}
