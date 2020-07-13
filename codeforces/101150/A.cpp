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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 10505
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int prime[MX];
int flag[MX];

void sieve() {
    prime[1] = 2;
    int pos = 2;
    for(ll i = 3; i < MX; i+=2) {
        if(flag[i]) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+=2*i)
            flag[j] = 1;
    }
    for(int i = 1; i < pos; i++)
        prime[i] += prime[i-1];
    memset(flag,0,sizeof flag);
    for(int i = 0; i < pos; i++)
    {
        for(int j = i+1; j < pos; j++)
        {
            if(prime[j]-prime[i] >= MX) break;
            flag[prime[j]-prime[i]]++;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        printf("%d\n", flag[n]);
    }
    return 0;
}

