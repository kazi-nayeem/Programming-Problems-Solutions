#include<stdio.h>

int main()
{
    unsigned long long int m, n;
    unsigned int flag , one , sum;
    while(scanf("%llu %llu", &m, &n) == 2)
    {
        if(m == 0 && n == 0) break;
        flag = 0;
        one = 0;
        while(m > 0 || n > 0)
        {
            sum = m % 10 + n %10;
            if(flag)
            {
                sum++;
                flag = 0;
            }
            if(sum > 9)
            {
                one++;
                flag = 1;
            }
            m /= 10;
            n /= 10;
        }
        if(one == 0)
            printf("No carry operation.\n");
        else if(one == 1)
            printf("1 carry operation.\n");
        else
            printf("%u carry operations.\n", one);
    }
    return 0;
}
