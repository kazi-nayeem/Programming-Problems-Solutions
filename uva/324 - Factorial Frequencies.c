#include<stdio.h>

#define MAX 1000

int arr[MAX];
int flag[10];

void longfact(int n);

int main()
{
    int n, i;
    while(scanf("%d", &n) == 1)
    {
        longfact(n);
        printf("%d! --\n", n);
        for(i = 0; i < 5; i++)
        {
            printf("   (%d)%5d", i, flag[i]);
            flag[i] = 0;
        }
        putchar('\n');
        for(;i < 10; i++)
        {
            printf("   (%d)%5d", i, flag[i]);
            flag[i] = 0;
        }
        putchar('\n');
    }
    return 0;
}

void longfact(int n)
{
    int i, j;
    int rem = 0, total, count;
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
        i = MAX;
    }
    for(count = 0; arr[count] == 0; count++);
    for(; count < MAX; count++)
    {
        flag[arr[count]]++;
        arr[count] = 0;
    }
    return;
}

