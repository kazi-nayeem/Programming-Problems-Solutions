#include<stdio.h>

int main()
{
    float hour, minute, angle;
    while(scanf(" %f:%f", &hour, &minute) == 2)
    {
        if(hour == 0 && minute == 0) break;
        angle = 5.5 * minute - 30 * hour;
        if(angle<0)
            angle += 360;
        if(angle > 180)
            angle = 360 - angle;
        printf("%.3f\n", angle);
    }
    return 0;
}
