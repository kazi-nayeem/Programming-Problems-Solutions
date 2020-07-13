#include<stdio.h>
#include<string.h>

#define MX 4000101

typedef unsigned long long int ull;

int phi[MX];
ull sum[MX];

void phi_function(void);
void sum_function(void);

int main()
{
    phi_function();
    sum_function();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        printf("%llu\n", sum[n]);
    }
    return 0;
}

void phi_function(void)
{
    register int i, j;
    for(i = 2; i < MX; i++) phi[i] = i;
    for(i = 2; i < MX; i++)
    {
        if(phi[i] == i)
            for(j = i; j < MX; j += i)
                phi[j] -= phi[j]/i;
    }
    return;
}
void sum_function(void)
{
    register int i, j;
    for(i = 2; i < MX; i++)
    {
        sum[i] += sum[i-1]+phi[i];
        for(j = i + i; j < MX; j+=i)
            sum[j] += i * phi[j/i];
    }
    return ;
}

