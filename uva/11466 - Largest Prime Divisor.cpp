#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define ll long long
#define MX 10000500
#define MXP 664604

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
    //printf("%d\n%lld\n", pos, num[pos-1]);
}

int main()
{
    sieve();
    ll int n;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0LL) return 0;
        n = abs(n);
        ll root = sqrt(n);
        int flag = 1, f = 1;
        for(int i = 0; num[i] <= root; i++)
        {
            f = 1;
            while(n%num[i] == 0)
            {
                f = flag = 0;
                n /= num[i];
            }
            if(f == 0)
                root = sqrt(n);
        }
        if(flag==1 || n == 1LL)
            n = -1LL;
        printf("%lld\n", n);
    }
    return 0;
}
