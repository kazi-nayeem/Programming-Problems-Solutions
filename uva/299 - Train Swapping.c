#include<stdio.h>

#define MAX 50

int main()
{
    int i, j, temp;
    int test;
    int n, flag;
    int train[MAX];
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(flag = 0, i = 0; i < n; i++)
            scanf("%d", &train[i]);
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
            {
                if(train[i] > train[j])
                {
                    temp = train[i];
                    train[i] = train[j];
                    train[j] = temp;
                    flag++;
                }
            }
        printf("Optimal train swapping takes %d swaps.\n", flag);
    }
    return 0;
}
