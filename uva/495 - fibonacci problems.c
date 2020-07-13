#include<stdio.h>
#include<math.h>

int main()
{
    float a , b, c;
    int n;
    while(scanf("%d", &n) == 1)
    {
        a = (1 + sqrt(5)) / 2;
        b = (1 - sqrt(5)) / 2;
        c = pow(a, n) - pow(b, n);
        c = c / sqrt(5);
        printf("The Fibonacci number for %d is %.0f\n", n, c);
    }
    return 0;
}
