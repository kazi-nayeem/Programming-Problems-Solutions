#include<stdio.h>
#define MAX 4000005

unsigned long long int great[MAX];
void gcd(void);

int main()
{
    gcd();
    long int n;
    while(scanf("%ld", &n) == 1 && n != 0)
        printf("%llu\n", great[n]);
    return 0;
}

void gcd(void)
{
    register long int i, j, k;
    register long int temp1, temp2, gcd;
    register long long int total;
    for(total = 0, i = 1; i < MAX; i++)
    {
        for(j = 1; j < i; j++)
        {
            for(temp1 = i, gcd = j, temp2 = temp1 % gcd;temp2 != 0; )
            {
                temp1 = gcd;
                gcd = temp2;
                temp2 = temp1 % gcd;
            }
            total += gcd;
        }
        great[i] = total;
    }
    return;
}
