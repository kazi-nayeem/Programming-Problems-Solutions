#include<stdio.h>

int main()
{
    int present, last, press;
    while(scanf("%d %d", &present, &last) == 2)
    {
        if(present == -1 && last == -1) break;
        if(present > last)
            press = present - last;
        else
            press = last - present;
        if(press > 50)
            press = 100 - press;
        printf("%d\n", press);
    }
    return 0;
}
