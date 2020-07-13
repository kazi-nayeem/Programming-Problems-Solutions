#include<stdio.h>
#define MAXF 1010
#define MAXP 170
int binary(int n);
void sieve(void);
int flag[MAXF];
int prime[MAXP];

int main()
{
    sieve();
    int number;
    int hwmaynu;
    int pos, i, j;
    while(scanf("%d %d", &number, &hwmaynu) == 2)
    {
        printf("%d %d:", number, hwmaynu);
        pos = binary(number);
        if(pos + 1 <= hwmaynu * 2)
            i = 0, j = pos;
        else
        {
            if(pos & 1)
            {
                i = (pos/2) - hwmaynu + 1;
                j = (pos / 2) + hwmaynu;
            }
            else
            {
                i = (pos/2) - hwmaynu + 1;
                j = (pos/2) + hwmaynu - 1;
            }
        }
        for(;i <= j; i++)
            printf(" %d", prime[i]);
        printf("\n\n");
    }
    return 0;
}
int binary(int n)
{
    int beg = 0;
    int end = MAXP - 1;
    int mid;
    for(mid = (beg + end) >> 1; beg < end;)
    {
        if(prime[mid] > n)
            end = mid - 1;
        else if (prime[mid] < n)
            beg = mid + 1;
        else
            break;
        mid = (beg + end) >> 1;
    }
    if(prime[mid] == n)
        return mid;
    if(prime[mid] > n)
        return mid - 1;
    return mid;
}

void sieve(void)
{
    int i, j, k = 2;
    int add;
    prime[0] = 1;
    prime[1] = 2;
    for(i = 4; i < MAXF; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAXF; i+=2)
    {
        if(flag[i] == 0)
        {
            prime[k++] = i;
            if(MAXF/i >= i)
            {
                add = i * 2;
                for(j = i * i; j < MAXF; j += add)
                    flag[j] = 1;
            }
        }
    }
    return;
}

