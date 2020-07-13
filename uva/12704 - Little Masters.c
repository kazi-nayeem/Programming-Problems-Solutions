#include<stdio.h>
#include<math.h>

int main()
{
    int x, y, r;
    int test;
    float f;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &x, &y, &r);
        f = (float) sqrt(x*x+y*y);
        printf("%.2f %.2f\n", (float)r - f,(float) r + f);
    }
    return 0;
}
