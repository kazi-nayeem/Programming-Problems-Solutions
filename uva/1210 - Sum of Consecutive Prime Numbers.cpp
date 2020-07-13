#include<cstdio>
using namespace std;

#define MX 10005
#define mx 1229

int prime[mx];
int flag[MX];
int arr[MX];

void sieve(void);

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        printf("%d\n", arr[n]);
    }
    return 0;
}

void sieve(void)
{
    prime[0] = 2;
    int k = 1;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            prime[k++] = i;
            int ad = i << 1;
            for(int j = i * i; j < MX; j += ad)
                flag[j] = 1;
        }
    }
    int s;
    for(int i = 0; i < mx; i++)
        for(int j = i, s = 0; j < mx; j++){
            s += prime[j];
            if(s < MX) arr[s]++;
            else break;
    }
    return;
}
