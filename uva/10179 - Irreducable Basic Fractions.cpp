#include<cstdio>
#include<cstring>
using namespace std;

#define MXF 31700
#define MXP 3409

int flag[MXF];
int prime[MXP];

void sieve(void);
long long int fraction(long long int n);

int main()
{
    sieve();
    long long int n;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0) return 0;
        printf("%lld\n", fraction(n));
    }
    return 0;
}

long long int fraction(long long int n)
{
    long long int total = n;
    for(int i = 0; n > 1 && i < MXP ; i++)
    {
        if(n % prime[i] == 0)
        {
            total = (total * prime[i] - total) / prime[i];
            do
            {
                n /= prime[i];
            }while(n % prime[i] == 0);
        }
    }
    if(n > 1)
        total = (total * (n - 1)) / n;
    return total;
}

void sieve(void)
{
    prime[0] = 2;
    int k = 1;
    for(int i = 3; i < MXF; i+=2)
    {
        if(flag[i] == 0)
        {
            prime[k++] = i;
            int ad = i + i;
            for(int j = i * i; j < MXF ; j += ad)
                flag[j] = 1;
        }
    }
    return;
}
