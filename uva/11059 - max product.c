#include<stdio.h>

int main()
{
    long long max_product;
    int test = 1, number;
    int negative, n;
    while(scanf(" %d", &n) == 1)
    {
        max_product = 1;
        negative = -11;
        while(n--)
        {
            scanf(" %d", &number);
            if(number != 0)
            {
                max_product *= number;
                if(number < 0 && negative < number)
                        negative = number;
            }
            else
            {
                for(;--n ;)
                    scanf(" %d", &number);
            }
        }
        if(max_product < 0)
            max_product /= negative;
        printf("Case #%d: The maximum product is %lld.\n", test++, max_product);
    }
    return 0;
}
