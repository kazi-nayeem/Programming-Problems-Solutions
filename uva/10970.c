#include<stdio.h>

int main()
{
    int m, n, sum;
    scanf("%d %d", &m, &n);
    if( m>=1 && m<=300 && n>=1 && n<=300)
    {
        sum = m * n;
        sum--;
    }
    printf("%d", sum);
    return 0;
}
