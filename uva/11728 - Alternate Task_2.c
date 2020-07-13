#include<stdio.h>
#include<math.h>
#define MAX 1001

int print[MAX];

void task(void);
int main()
{
    task();
    int n;
    int test=1;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        if(print[n] == 0)
            printf("Case %d: -1\n", test++);
        else
            printf("Case %d: %d\n", test++, print[n]);
    }
}

void task(void)
{
    int i, j, total;
    for(i = 1; i < MAX;i++)
    {
        total = 0;
        for(j = 1; j <= i;j++)
        {
            if(i%j == 0)
            {
                total += j;
            }
        }
        if(total < MAX)
            print[total] = i;
    }
    return;
}
