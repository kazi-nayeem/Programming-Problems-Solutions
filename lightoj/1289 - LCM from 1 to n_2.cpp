#include<cstdio>
using namespace std;

#define MAX 1000001

int mode[MAX];

int main()
{
    unsigned long long int mod = 4294967296llu;
    mode[1] = 1;
    unsigned long long int number, coun, lcm, gcd;
    unsigned long long int temp1, temp2, temcount;
    long int ten = 0, di;
    for(lcm = 1, coun = 2; coun < MAX ; ++coun)
    {
        temcount = coun;
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
        for(;(lcm%mod == 0); lcm = lcm / mod);
        mode[count] = lcm % 10;
    }
    while(scanf("%llu" , &number) == 1 && (number != 0))
        printf("%d\n", mode[number]);
    return 0;
}
