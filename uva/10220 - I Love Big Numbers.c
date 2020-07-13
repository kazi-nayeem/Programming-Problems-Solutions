#include<stdio.h>

#define MAX 2700

int arr[MAX];

long int longfact(int n);

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
     {
         printf("%ld\n", longfact(n));
     }
    return 0;
}

long int longfact(int n)
{
    int i, j;
    int rem = 0, count;
    long int total;
    i = MAX -1;
    arr[i] = 1;
    for(count = 2; count <= n; count++)
    {
        while(i>0)
        {
            total = arr[i] * count + rem;
            rem = 0;
            if(total > 9)
            {
                arr[i] = total % 10;
                rem = total / 10;
            }
            else
            {
                arr[i] = total;
            }
            i--;
        }
        rem = 0;
        total = 0;
        i = MAX - 1;
    }
    total = 0;
    for(count = 0; count < MAX; count++)
    {
        total += arr[count];
        arr[count] = 0;
    }
    return total;
}

