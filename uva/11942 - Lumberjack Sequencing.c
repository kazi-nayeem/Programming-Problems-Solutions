#include<stdio.h>

#define MAX 10

int main()
{
    int hight[MAX];
    int count, n;
    int flag;
    printf("Lumberjacks:\n");
    scanf(" %d", &n);
    while(n--)
    {
        for(flag = 1, count = 0; count < MAX ; ++count)
            scanf(" %d", hight + count);
        if(hight[0] < hight[9])
        {
            for(count = 1; count < MAX ; ++count)
                if(hight[count-1] > hight[count])
                {
                    flag = 0;
                    break;
                }
        }
        else
        {
            for(count = 1; count < MAX ; ++count)
                if(hight[count-1] < hight[count])
                {
                    flag = 0;
                    break;
                }
        }
        if(flag)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
