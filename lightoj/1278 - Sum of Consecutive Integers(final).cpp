#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#define MX 10000050
#define MXP 664580
#define ll long long

char flag[(MX>>3)+5];
int prime[MXP];
vector<pair<ll,int> > factor;
vector<ll> divisor;

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
    prime[0] = 2;
    int pos = 1;
    for(ll i = 3; i < MX; i+=2)
    {
        if(check(i)) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+= i<<1)
            input(j);
    }
    printf("%d\n", pos);
    printf("%d %d\n", prime[pos-3], prime[pos-5]);
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
        scanf(" %lld", &n);
        fact(n);
        divisor.clear();
        backtrack(0,1LL);
        int res = 0;
        for(int i = 0; i < divisor.size(); i++)
        {
            if(divisor[i]%2ll)
            {
                if(((n/divisor[i])-(divisor[i]/2))>0)
                    res++;
            }
            else
            {
                if(((n/divisor[i])-(divisor[i]/2))>0)
                    res++;
            }
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
