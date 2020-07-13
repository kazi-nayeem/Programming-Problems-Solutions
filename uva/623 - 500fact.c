#include<stdio.h>

#define MAX 1050
#define MAXF 1050

char fact[MAXF][MAX];

void longfact(void);

int main()
{
    longfact();
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("%s\n", fact[n]);
    }
    return 0;
}

void longfact(void)
{
    fact[0][0] = '0';
    fact[0][1] = '\0';
    fact[1][0] = '1';
    fact[1][1] = '\0';
    int i, j;
    int arr[MAX];
    long long int rem = 0, count;
    long long int total;
    i = MAX -1;
    arr[i] = 1;
    for(count = 2; count < MAXF; count++)
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
        for(i = 0, j = 0, total = 0; i < MAX; i++)
        {
            if(total == 1 || arr[i] > 0)
            {
                total = 1;
                fact[count][j++] = arr[i] + '0';
            }
        }
        fact[count][j] = '\0';
        rem = 0;
        total = 0;
        i = MAX - 1;
    }
    return;
}

