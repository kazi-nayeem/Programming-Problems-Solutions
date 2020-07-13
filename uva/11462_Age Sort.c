#include<stdio.h>
#include<stdlib.h>

int age[2000000];

int comp(const void *a, const void *b)
{
    return (*(int*) a - *(int *) b);
}
int main()
{
    long int n, i;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        for(i = 0; i < n; ++i)
            scanf("%d", &age[i]);
        qsort(age, n, sizeof(int),comp);
        printf("%d", age[0]);
        for(i = 1; i < n ; ++i)
            printf(" %d", age[i]);
        printf("\n");
    }
    return 0;
}
