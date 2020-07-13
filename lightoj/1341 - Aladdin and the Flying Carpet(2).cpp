#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#define MX 1000050
#define MXP 78502
#define ll long long

char flag[MX];
int prime[MXP];
vector<pair<ll,int> > factor;
vector<ll> divisor;

void sieve(void )
{
    prime[0] = 2;
    int pos = 1;
    for(ll i = 3; i < MX; i+=2)
    {
        if(flag[i]) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+= i<<1)
            flag[j] = 1;
    }
    //printf("%d\n", pos);
    return;
}

void fact(ll n)
{
    factor.clear();
    int root = sqrt(n);
    for(int i = 0; i < MXP && root >= prime[i]; i++)
    {
        int tk = 0;
        while(n%prime[i] == 0)
        {
            tk++;
            n /= prime[i];
        }
        if(tk == 0) continue;
        factor.push_back(make_pair(prime[i],tk));
        root = sqrt(n);
    }
    if(n>1)
        factor.push_back(make_pair(n,1));
    return;
}

void backtrack(int pos, ll num)
{
    if(pos == factor.size())
    {
        divisor.push_back(num);
        return;
    }
    backtrack(pos+1,num);
    for(int i = 0; i < factor[pos].second; i++)
    {
        num *= factor[pos].first;
        backtrack(pos+1,num);
    }
    return;
}

int main()
{
    sieve();
    int te, ti;
    ll n, res, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &n, &m);
        fact(n);
        divisor.clear();
        backtrack(0,1LL);
        int res = 0;
        for(int i = 0; i < divisor.size(); i++)
        {
            if(divisor[i] >= m && divisor[i] < n/divisor[i] && n/divisor[i] >= m) res++;
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
