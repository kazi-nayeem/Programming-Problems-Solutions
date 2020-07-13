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

#define MX 300005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct data {
    int id;
    ll start, bur;
    data(int i, ll a, ll b) {
        id = i;
        start = a;
        bur = b;
    }
};

ll res[MX];

ll now;
int k;

queue<data> qu;

void addd(data a) {
    while(!qu.empty()) {
        ll tot = max(now,qu.front().start)+qu.front().bur;
        //printf("%d %lld\n", qu.front().id, tot);
        if(tot > a.start) break;
        now = tot;
        res[qu.front().id] = now;
        qu.pop();
    }
    if(qu.size()<=k){
        qu.push(a);
    }else{
        res[a.id] = -1;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        ll st, bu;
        scanf("%lld %lld", &st,&bu);
        addd(data(i,st,bu));
    }
    while(!qu.empty()) {
        ll tot = max(now,qu.front().start)+qu.front().bur;
        //printf("%d %lld\n", qu.front().id, tot);
        now = tot;
        res[qu.front().id] = now;
        qu.pop();
    }
    for(int i = 1; i <= n; i++){
        printf("%lld\n", res[i]);
    }
    return 0;
}


