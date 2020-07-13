#include<stdio.h>
#include<string.h>

#define MAX 2001

int flag[MAX];
int prime[123];

void sieve(void);

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
        for(i = 0; i < len; i++)
        {
            prime[(int)input[i]]++;
        }
        for(i = 48; i < 123; i++)
        {
            if(prime[i])
            {
                if(!flag[prime[i]])
                {
                    putchar(i);
                    j = 0;
                }
                prime[i] = 0;
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

