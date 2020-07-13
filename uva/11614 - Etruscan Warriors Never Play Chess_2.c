#include<stdio.h>
#include<math.h>

#define ull unsigned long long int

int main()
{
    ull n;
    ull s;
    ull t;
    scanf(" %llu", &t);
    while(t--)
    {
        scanf(" %llu", &n);
        s = sqrt((8 * n) + 1);
        s = (s - 1) / 2;
        printf("%llu\n", s);
    }
    return 0;
}
