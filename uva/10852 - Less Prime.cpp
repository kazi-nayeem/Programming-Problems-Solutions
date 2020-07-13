#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;


#define MX 10050
#define MXP 1233
#define ll long long int

int prime[MXP];
int check[10005];

void sieve(void)
{
    prime[0] = 2;
    int pos = 1;
    for(ll i = 3; i < MX; i+=2)
    {
        if(check[i] == 0)
        {
            prime[pos++] = i;
            for(ll j = i*i; j < MX; j+= i<<1)
                check[j] = 1;
        }
    }
    //printf("%d\n", pos);
}

int main()
{
    sieve();
    int n, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        int p, mx = 0;
        for(int i = 0; prime[i] < n; i++)
        {
            if(n%prime[i]>mx)
            {
                mx = n%prime[i];
                p = prime[i];
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
