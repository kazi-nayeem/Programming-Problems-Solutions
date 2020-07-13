#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#define MX 1000050
#define MXF 100000000500ll
#define MXP 78501
#define ll long long

char flag[(MX>>3)+5];
int prime[MXP];
vector<ll> vc;

inline int check(int num)
{
    return (flag[num>>3]>>(num& 0b111))&1;
}

inline void input(int num)
{
    flag[num>>3] |= 1<<(num& 0b111);
    return;
}

void sieve(void )
{
    int pos = 0;
    for(ll i = 3; i < MX; i+=2)
    {
        if(check(i)) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+= i<<1)
            input(j);
    }
    printf("%d\n", pos);
    return;
}

void backtrack(int pos, ll num)
{
    if(num > MXF) return;
    if(pos == -1)
    {
        vc.push_back(num);
        return;
    }
    backtrack(pos-1,num);
    num *= (ll) prime[pos]*prime[pos];
    while(num < MXF)
    {
        backtrack(pos-1,num);
        num *= prime[pos];
    }
    return;
}

int main()
{
    sieve();
    backtrack(MXP-1,1LL);
    int te, ti;
    ll n, res, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %lld", &n);
        int res = 0;
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
