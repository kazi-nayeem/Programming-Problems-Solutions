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
    int i, j, total, k;
    double sqr;
    int root;
    print[1] = 1;
    for(i = 2; i < MAX;i++)
    {
        sqr = sqrt(i);
        root = (int) sqr;
        if(root == sqr)
            total = i + 1 - root;
        else
            total = i + 1;
        for(j = 2; j <= root;j++)
        {
            if(i%j == 0)
            {
                total += j + (i/j);
            }
        }
        if(total > 0 && total < MAX)
            print[total] = i;
    }
    return;
}
