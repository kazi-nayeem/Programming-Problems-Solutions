#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 1000505
#define UL unsigned long long int

int phi[MX];
int res[MX];

void funct(void);

int main()
{
    funct();
    int te, ti, n, x;
    long long total;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            total += res[x];
        }
        printf("Case %d: %lld Xukha\n", te, total);
    }
    return 0;
}

void funct(void)
{
    for(int i = 1; i < MX; i++)
    {
        phi[i] = i;
        res[i] = MX+5;
    }
    for(int i = 2; i < MX; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i ; j < MX; j += i)
                phi[j] -= phi[j] / i;
        }
        res[phi[i]] = min(res[phi[i]],i);
    }
    for(int i = MX-3; i>=0; i--)
    {
        res[i] = min(res[i],res[i+1]);
    }
    return;
}

