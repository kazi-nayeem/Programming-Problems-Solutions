#include<stdio.h>

#define MAX 1000001

int mode[MAX];

int main()
{
    mode[1] = 1;
    unsigned long long int number, count, lcm, gcd;
    unsigned long long int temp1, temp2, temcount;
    long int ten = 0, di;
    for(lcm = 1, count = 2; count < MAX ; ++count)
    {
        temcount = count;
        for(di = 0;((lcm % 2) == 0) && di < ten;di++)
            temcount = temcount >> 1;
        for(di = 0;((lcm % 5) == 0) && di < ten;di++)
            temcount = temcount / 5;
        for(temp1 = lcm, gcd = temcount;(temp1%gcd != 0);)
        {
            temp2 = temp1%gcd;
            temp1 = gcd;
            gcd = temp2;
        }
        lcm = lcm * temcount / gcd;
        for(;(lcm%10 == 0); lcm /= 10)
            ten++;
        mode[count] = lcm % 10;
    }
    while(scanf("%llu" , &number) == 1 && (number != 0))
        printf("%d\n", mode[number]);
    return 0;
}
