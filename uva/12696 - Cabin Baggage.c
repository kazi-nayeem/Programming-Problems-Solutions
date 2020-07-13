#include<stdio.h>

int main()
{
    float x, y, z, weight;
    int time, allow = 0;
    scanf("%d", &time);
    while(time--)
    {
        scanf("%f %f %f %f", &x, &y, &z, &weight);
        if( weight <= 7 && ((x<=56 && y <= 45 && z <= 25) || ( x + y + z <= 125)))
        {
            puts("1");
            allow++;
        }
        else
            puts("0");

    }
    printf("%d\n", allow);
    return 0;
}
