#include<stdio.h>
#include<string.h>
#include<math.h>

#define lli long long int

#define MX 1000000100

char flag[MX/8+1];


void sieve(void);
void input(lli n);
int output(lli n);

int main()
{
    sieve();
    int i;
    for(i = 0; i < 100; i++)
        if(output(i))
        printf("%d\n", i);
}

void sieve(void)
{
    lli root = (lli) sqrt(MX);
    input(0);
    input(1);
    lli i, j, ad;
    for(i = 4; i < MX; i+=2)
        input(i);
    for(i = 3; i < root; i+=2)
    {
        if(output(i))
        {
            ad = i << 1;
            for(j = i * i; j < MX; j += ad)
                input(j);
        }
    }
    return;
}
void input(lli n)
{
    lli pos, num;
    num = n / 8;
    pos = n % 8;
    flag[num] = flag[num] | (1 << pos);
}
int output(lli n)
{
    lli pos, num;
    num = n / 8;
    pos = n % 8;
    if((flag[num] >> pos) & 1) return 0;
    return 1;
}
