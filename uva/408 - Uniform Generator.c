#include<stdio.h>

int main()
{
    long int n, m;
    long int temp1, temp2, gcd;
    while(scanf("%ld %ld", &n, &m) == 2)
    {
        for(gcd = n, temp1 = m; (temp1 % gcd != 0);)
        {
            temp2 = temp1 % gcd;
            temp1 = gcd;
            gcd = temp2;
        }
        if(gcd == 1)
            printf("%10ld%10ld    Good Choice\n\n", n, m);
        else
            printf("%10ld%10ld    Bad Choice\n\n", n, m);
    }
    return 0;
}
