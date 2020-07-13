#include<stdio.h>
#include<stdlib.h>

#define MAXC 55
#define MAXS 100

#define total(s,t) for(i = 0, t = 0; i < len;i++)\
                    for(j = i + 1; j < len; j++)\
                        if(s.str[i] > s.str[j])\
                            t++;


typedef struct{
    char str[MAXC];
} mystring;

int len;

int comp(const void *a, const void *b)
{
    int j, i, t1, t2;
    mystring first, second;
    first = *(mystring *)a;
    second = *(mystring *)b;
    total(first,t1);
    total(second,t2);
    return t1 - t2;
}

int main()
{
    int test, f = 0;
    mystring dna[MAXS];
    int n, i;
    scanf("%d", &test);
    while(test--)
    {
        if(f) putchar('\n');
        f = 1;
        scanf("%d%d", &len, &n);
        getchar();
        for(i = 0; i < n; i++)
            gets(dna[i].str);
        qsort(dna,n,sizeof(mystring),comp);
        for(i = 0; i < n; i++)
            puts(dna[i].str);
    }
    return 0;
}
