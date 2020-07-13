#include<stdio.h>

#define MAX 1000050

void sieve(void);

int flag[MAX];
int diff[200];

int main()
{
    sieve();
    int time, maxd, di;
    long int low, high;
    long int i, j;
    long int temp;
    scanf("%d", &time);
    while(time--)
    {
        temp = j = 0;
        scanf("%ld %ld", &low, &high);
        if(low < 3 && high > 2)
        {
            i = 3;
            diff[1] = 1;
            maxd = 1;
        }
        else if(low % 2 == 0)
            i = low + 1;
        else
            i = low;
        for(;i <= high; i+=2)
        {
            if(flag[i] == 0 && temp != 0)
            {
                di = i - temp;
                diff[di]++;
                if(maxd < di)
                    maxd = di;
                temp = i;
            }
            else if(flag[i] == 0)
                temp = i;
        }
        for(j = temp = 0,i = 1; i <= maxd; i++)
        {
            if(j <diff[i])
            {
                j = diff[i];
                temp = i;
            }
            else if(j == diff[i])
            {
                temp = 0;
            }
            diff[i] = 0;
        }
        if(temp == 0)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %d\n", temp);
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 1;
    flag[1] = 1;
    long long int i, j, k;
    for(i = 4; i < MAX; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAX; i+=2)
    {
        if(flag[i] == 0)
        {
            if(MAX / i >= i)
            {
                for(j = i * i, k = i << 1; j < MAX; j += k)
                    flag[j] = 1;
            }
        }
    }
    return;
}
