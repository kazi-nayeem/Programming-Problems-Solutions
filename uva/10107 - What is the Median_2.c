#include<stdio.h>

#define MAX 10001

void input(long int *arr, const int n, long int temp);

int main()
{
    int n = 0;
    long int arr[MAX], temp;
    while(scanf("%lld", &temp) == 1)
    {
        input(arr,n,temp);
        n++;
        if((n%2) == 1)
        {
            printf("%ld\n", arr[(n/2)]);
        }
        else
        {
            printf("%ld\n", (arr[n/2] + arr[(n/2) - 1]) / 2);
        }

    }
    return 0;
}

void input(long int *arr, const int n, long int temp)
{
    if(n == 0)
    {
        arr[0] = temp;
        return;
    }
    int i;
    long int ftemp;
    for(i = 0; i < n; i++)
        if(arr[i] > temp)
            break;
    ftemp = arr[i];
    arr[i] = temp;
    for(i = i + 1; i < n; i++)
    {
        temp = arr[i];
        arr[i] = ftemp;
        ftemp = temp;
    }
    arr[n] = ftemp;
    return ;
}
