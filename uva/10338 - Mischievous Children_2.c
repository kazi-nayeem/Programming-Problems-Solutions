#include<stdio.h>
#include<string.h>

#define MAX 21

#define ull unsigned long long int

ull factorial[MAX];
int flag[91];

int main()
{
    ull fact;
    int n, t;
    int len, i, j;
    char word[MAX];
    factorial[1] = 1;
    for(t = 2; t < MAX; ++t)
        factorial[t] = t * factorial[t-1];
    scanf(" %d", &n);
    for(t = 0; t < n;)
    {
        scanf(" %s", word);
        len = strlen(word);
        fact = factorial[len];
        for(i = 0; i < len; ++i)
        {
            flag[(int ) word[i]]++;
        }
        for(i = 65; i < 91; i++)
        {
            if(flag[i] > 1)
            {
                fact /= factorial[flag[i]];
                flag[i] = 0;
            }
            else
                flag[i] = 0;
        }
        printf("Data set %d: %llu\n", ++t, fact);
    }
    return 0;
}
