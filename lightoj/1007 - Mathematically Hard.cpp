#include<cstdio>
#include<cstring>
using namespace std;

#define MX 5000005
#define UL unsigned long long int
UL phi[MX];

void funct(void);

int main()
{
    funct();
    int te, ti, a, b;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", te, phi[b]-phi[a-1]);
    }
    return 0;
}

void funct(void)
{
    for(int i = 1; i < MX; i++)
        phi[i] = i;
    for(int i = 2; i < MX; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i ; j < MX; j += i)
                phi[j] -= phi[j] / i;
        }
        phi[i] *= phi[i];
        phi[i] += phi[i-1];
    }
    return;
}
