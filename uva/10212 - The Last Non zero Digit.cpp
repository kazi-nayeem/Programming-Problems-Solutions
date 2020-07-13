#include<cstdio>
using namespace std;

int main()
{
    long long int n, m, i, c, total;
    while(scanf("%lld %lld", &n, &m) == 2)
    {
        total = 1;
        c = n-m+1;
        for(i = n; i >= c; i--)
        {
            total *= i;
            while(total%10 == 0)
                total /= 10;
            total %= 1000000000;
        }
        printf("%lld\n", total % 10);
    }
    return 0;
}

