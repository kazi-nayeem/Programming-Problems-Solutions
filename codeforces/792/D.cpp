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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

ll moveUp(ll n) {
    for(int i = 0; i < 64; i++) {
        if(((n>>i)&1) == 0) continue;
        if(((n>>(i+1))&1) == 1) {
            return n^(1ll<<i);
        }
        return n^(3ll<<i);
    }
    return 0;
}

ll moveLeft(ll n) {
    for(int i = 0; i < 64; i++) {
        if(((n>>i)&1) == 0) continue;
        if(i == 0) return n;
        return n^(3ll<<(i-1));
    }
    return 0;
}
ll moveRight(ll n) {
    for(int i = 0; i < 64; i++) {
        if(((n>>i)&1) == 0) continue;
        if(i == 0) return n;
        return n^(1ll<<(i-1));
    }
    return 0;
}

char str[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, x;
    int q;
    scanf("%I64d %d", &n, &q);
    while(q--) {
        scanf("%I64d %s", &x, str);
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            if(str[i] == 'R') {
                x = moveRight(x);
            } else if(str[i] == 'L') {
                x = moveLeft(x);
            }else{
                ll tem = moveUp(x);
                if(tem < n) x = tem;
            }
        }
        printf("%I64d\n", x);
    }
    return 0;
}

