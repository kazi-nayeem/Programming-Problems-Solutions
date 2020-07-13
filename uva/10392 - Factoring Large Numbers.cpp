#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define ll long long
#define MX 1000500
#define MXP 78537

char flag[MX];
ll int num[MXP];

void sieve(void)
{
    num[0] = 2;
    int pos = 1;
    for(ll int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            num[pos++] = i;
            for(ll int j = i*i; j < MX; j+=i<<1)
                flag[j] = 1;
        }
    }
//    printf("%d\n%lld\n", pos, num[pos-1]);
}

int main()
{
    sieve();
    ll int n;
    while(scanf("%lld", &n) == 1)
    {
        if(n < 0LL) return 0;
        if(n == 1)
        {
            puts("    1\n");
            continue;
        }
        ll root = sqrt(n);
        int  f = 1;
        for(int i = 0; i < MXP && num[i] <= root; i++)
        {
            f = 1;
            while(n%num[i] == 0)
            {
                n /= num[i];
                printf("    %lld\n", num[i]);
            }
            if(f == 0)
                root = sqrt(n);
        }
        if(n != 1LL)
            printf("    %lld\n", n);
        puts("");
    }
    return 0;
}
