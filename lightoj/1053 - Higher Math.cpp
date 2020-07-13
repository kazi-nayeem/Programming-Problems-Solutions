#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int a, b, c, ti, te;

    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %d %d %d", &a, &b, &c);
        if(a>b)
            a ^= b ^= a ^= b;
        if(b > c)
            b ^= c ^= b ^= c;
        if(a > c)
            a ^= c ^= a ^= c;

        if(a*a + b*b == c*c)
            printf("Case %d: yes\n", te);
        else
            printf("Case %d: no\n", te);
    }
    return 0;
}
