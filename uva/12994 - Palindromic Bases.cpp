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

#define MX 10005005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

char flag[MX];

ll prime[MX];
int pos;

vector<pair<ll,int> > fact;

void sieve() {
    prime[0] = 2;
    pos = 1;

    for(ll i = 3; i < MX; i+=2) {
        if(flag[i] == 0) {
            prime[pos++] = i;
            for(ll j = i*i; j < MX; j+=i<<1)
                flag[j] = 1;
        }
    }
    //printf("%d\n", pos);
    //for(int i = 0; i < 100; i++)
    // printf("%lld\n", prime[i]);
}

void factorize(ll n) {
    fact.clear();
    for(int i = 0; i < pos && (prime[i]*prime[i] <= n); i++) {
        int cnt = 0;
        while(n%prime[i] == 0) {
            n /= prime[i];
            cnt++;
        }
        if(cnt == 0) continue;
        fact.push_back(make_pair(prime[i],cnt));
    }
    if(n > 1) {
        fact.push_back(make_pair(n,1));
    }
    return;
}

vector<ll> divisor;

void backtrack(int pos, ll n) {
    if(pos == fact.size()) {
        divisor.push_back(n);
        return;
    }
    for(int i = 0; i <= fact[pos].second; i++) {
        backtrack(pos+1,n);
        n *= fact[pos].first;
    }
    return;
}

vector<ll> di;

int digi(ll n, ll p) {
    di.clear();
    //printf("%lld %lld\n", n, p);
    while(n>0)
    {
        di.push_back(n%p);
        n/=p;
    }

    //for(int i = 0; i < di.size(); i++)
        //printf("%d\n", di[i]);
    //puts("");
    if(di.size()%2 != 0) return 1;
    n = di.size();
    for(int i = 0; i < n; i++)
    {
        if(di[i] != di[n-i-1]) return 1;
    }
    //printf("ok");
    return 0;
}

int main() {
    sieve();
    int te, ti;
    ll n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++) {
        scanf("%lld", &n);
        factorize(n);
        //for(int i = 0; i < fact.size(); i++)
            //printf("%lld %d\n", fact[i].first, fact[i].second);
        divisor.clear();
        backtrack(0,1ll);
        sort(divisor.begin(),divisor.end());
        int res = 0;
        for(int i = 1; i < divisor.size(); i++) {
            if(divisor[i]-1 == divisor[i-1]) continue;
            if((digi(n,divisor[i]-1)%2) == 0) res++;
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}

/**
54184131565413
*/

