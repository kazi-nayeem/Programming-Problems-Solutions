#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 21

#define ull unsigned long long int

ull factorial[MAX];

int comp(const void *a, const void *b)
{
    return(int)(*(char*)a - *(char*) b);
}

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
        qsort(word, len, sizeof(char), comp);
        for(i = 0; i < len; ++i)
        {
            for(j = 1;word[i] == word[i+1];i++, j++);
            fact = fact / factorial[j];
        }
        printf("Data set %d: %llu\n", ++t, fact);
    }
    return 0;
}
