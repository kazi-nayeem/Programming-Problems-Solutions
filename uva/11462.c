#include<stdio.h>
#include<stdlib.h>

typedef struct {
    unsigned year : 7;
} tage;
int main()
{
    tage *age, temp;
    unsigned long int n, i, j, a, b;
    printf("%d", sizeof(tage));
    while(scanf("%ld", &n)==1)
    {
        if(n == 0) break;
        age = (tage *) malloc(n * sizeof(tage));
        for(i = 0; i < n ; ++i)
            scanf("%d", age + i);
        for(i = 0; i < n - 1; ++i)
            for(j = i + 1; j < n; ++j)
                {
                    a = (age + i)->year;
                    b = (age + j)->year;
                    if(a > b)
                    {
                        temp = *(age + i);
                        *(age+i) = *(age+j);
                        *(age+j) = temp;
                    }
                }
        for( i = 0; i < n ; ++i)
            printf("%d ", *(age+i));
        printf("\n");
    }
    return 0;
}
