#include<stdio.h>

int main()
{
    int n;
    int total, extra, new;
    while(scanf("%d", &n) == 1 && (n != 0) )
    {
        for(total = 0; n >= 3; n = extra + new)
        {
            extra = n % 3;
            new = n / 3;
            total += new;
        }
        if(n == 2)
            total++;
        printf("%d\n", total);
    }
    return 0;
}

