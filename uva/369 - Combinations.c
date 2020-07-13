#include<stdio.h>

#define ull unsigned long long int

int main()
{
    int n, i, k, l;
    ull combinations;
    while(scanf(" %d %d", &n, &i) == 2 && (n != 0 || i != 0))
    {
        for(k = n - i + 1, l = combinations = 1; k <= n; k++, l++)
            combinations = combinations * k / l;
        printf("%d things taken %d at a time is %llu exactly.\n", n, i, combinations);
    }
    return 0;
}
