#include<stdio.h>

#define MAX 52

long long int fibo[MAX];

int main()
{
    register int i;
    int test, num;
    fibo[0] = 1;
    fibo[1] = 2;
    for(i = 2; i < MAX ; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    scanf("%d", &test);
    for(i = 0; i < test; i++)
    {
        scanf("%d", &num);
        printf("Scenario #%d:\n%lld\n", i + 1, fibo[num]);
    }
    return 0;
}
