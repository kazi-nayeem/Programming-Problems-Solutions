#include<stdio.h>
#include<math.h>

int main()
{
    double diagonal;
    long long int n;
    int test = 1;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0) break;
        diagonal = (3 + sqrt(9 + (8 * n))) / 2;
        printf("Case %d: %.0lf\n", test++, ceil(diagonal));
    }
    return 0;
}
