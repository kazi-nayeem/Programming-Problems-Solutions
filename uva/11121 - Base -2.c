#include<stdio.h>

void base (long int n);

int main()
{
    int test, t;
    long int n;
    scanf("%d", &t);
    for(test = 0; test < t;)
    {
        scanf("%ld", &n);
        printf("Case #%d: ", ++test);
        if(n == 0)
            putchar('0');
        else
            base(n);
        putchar('\n');
    }
    return 0;
}

void base (long int n)
{
    if(n == 0) return;
    if(n < 0)
    {
        if(n % 2)
        {
            base((2-n)/2);
            putchar('1');
        }
        else
        {
            base(-(n/2));
            putchar('0');
        }
        return;
    }
    base(-(n/2));
    if(n % 2)
        putchar('1');
    else
        putchar('0');
    return;
}
