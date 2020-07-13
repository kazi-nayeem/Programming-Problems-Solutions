#include<stdio.h>

int main()
{
    int number[1000];
    int n, i, j;
    int flip;
    while(scanf("%d", &n) == 1)
    {
        for(flip = 0,i = 0; i < n ; ++i)
            scanf("%d", &number[i]);
        for(i = 0; i < n ; ++i)
        for(j = i + 1; j < n ; ++j)
            if(number[i] > number[j])
                    flip++;
        printf("Minimum exchange operations : %d\n", flip);
    }
    return 0;
}
