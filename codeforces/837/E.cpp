//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

vector<ll> prime;

void factor(ll a)
{
    prime.clear();
    for(ll i = 2; i*i<=a; i++)
    {
        while(a%i == 0)
        {
            prime.push_back(i);
            a /= i;
        }
    }
    if(a>1) prime.push_back(a);
}

ll find_max(ll b)
{
    ll ans = 0;
    for(int i = 0; i < prime.size(); i++)
    {
        ans = max(ans,(b/prime[i])*prime[i]);
    }
    return ans;
}

ll func(ll a, ll b)
{
    ll ans = 0;
    factor(a);
    while(b>0)
    {
        ll p = find_max(b);
        ans += b-p;
        b = p;
        for(int i = 0; i < prime.size(); i++)
        {
            if(p%prime[i]) continue;
            b /= prime[i];
            prime.erase(prime.begin()+i);
            break;
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a, b;
    scanf("%I64d %I64d", &a, &b);
    ll gcd = __gcd(a,b);
    a /= gcd;
    b /= gcd;
    printf("%I64d\n", func(a,b));
    return 0;
}

