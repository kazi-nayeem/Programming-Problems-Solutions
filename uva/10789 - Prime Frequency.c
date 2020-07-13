#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 2001

int flag[MAX];

void sieve(void);
int comp(const void *a, const void *b);

int main()
{
    sieve();
    char input[MAX];
    int i, j, len, k;
    int test, count = 1;
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        j = 1;
        gets(input);
        printf("Case %d: ", count++);
        len = strlen(input);
        qsort(input, len, sizeof(char), comp);
        for(i = 1; i < len; i++)
        {
            k = 1;
            while(input[i - 1] == input[i])
            {
                i++;
                k++;
            }
            if(!flag[k])
            {
                j = 0;
                putchar(input[i-1]);
            }
        }
        if(j)
            printf("empty");
        putchar('\n');
    }
    return 0;
}

void sieve(void)
{
    int i, j, add;
    flag[0] = 1;
    flag[1] = 1;
    for(i = 4; i < MAX ; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAX; i += 2)
    {
        if(!flag[i])
        {
            j = i * i;
            if(j < MAX)
            {
                for(add = i << 1; j < MAX; j += add)
                    flag[j] = 1;
            }
        }
    }
    return;
}

int comp(const void *a, const void *b)
{
    return (int )(*(char *) a - *(char *) b);
}
