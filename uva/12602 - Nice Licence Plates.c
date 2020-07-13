#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a, b, c;
    int num, t, total;
    scanf(" %d", &t);
    while(t--)
    {
        scanf(" %c%c%c-%d", &a, &b, &c, &num);
        total = (toascii(c) - 65) + ((toascii(b)- 65) * 26) + ((toascii(a)- 65) * 676);
        if(abs(total - num) < 101)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
