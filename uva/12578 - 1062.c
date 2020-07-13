#include<stdio.h>
#include<math.h>

#define PI acos(-1)

int main()
{
    int t;
    float l, area, red;
    scanf("%d", &t);
    while(t--)
    {
        scanf(" %f", &l);
        area = 0.6 * l * l;
        red = PI * l * l / 25;
        printf("%.2f %.2f", red, area - red);
    }
    return 0;
}
