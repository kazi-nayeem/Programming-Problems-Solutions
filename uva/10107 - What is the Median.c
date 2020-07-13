#include<stdio.h>
#include<stdlib.h>

#define MAX 10001

int comp(const void *a, const void *b)
{
    return (int)(*(long int *) a - *(long int *)b);
}
int main()
{
    int i = 0;
    long int arr[MAX];
    while(scanf("%ld", &arr[i]) == 1)
    {
        i++;
        qsort(arr,i,sizeof(long int),comp);
        if((i%2) == 1)
        {
            printf("%ld\n", arr[(i/2)]);
        }
        else
        {
            printf("%ld\n", (arr[i/2] + arr[(i/2) - 1]) / 2);
        }
    }
    return 0;
}
