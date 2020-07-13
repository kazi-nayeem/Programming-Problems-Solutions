#include<stdio.h>

int main()
{
    unsigned int t, tcount, a, b, sum;
    scanf("%u", &t);
    for(tcount = 0; tcount < t;)
    {
        scanf(" %u %u", &a, &b);
        if(a%2 == 0)
        ++a;
        for(sum = 0; a <= b; a += 2)
            sum += a;
        printf("Case %u: %u\n", ++tcount, sum);
    }
    return 0;
}
