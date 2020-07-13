#include<stdio.h>

#define MAX 50

long long int male[MAX];
long long int female[MAX];

int main()
{
    int n;
    male[0] = 0;
    female[0] = 1;
    for(n = 1; n < MAX; n++)
    {
        male[n] = male[n-1] + female[n-1];
        female[n] = male[n-1] + 1;
    }
    while(scanf("%d", &n) == 1)
    {
        if(n == -1) break;
        printf("%lld %lld\n", male[n], male[n]+ female[n]);
    }
    return 0;
}
