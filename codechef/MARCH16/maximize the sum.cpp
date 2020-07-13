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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll a[MX];
ll b[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for(int i = 0; i < n; i++)
            scanf("%lld", &b[i]);
        ll res = 0;
        int pos = 0;
        for(int i = 0; i < n; i++) {
            res += a[i]*b[i];
            if(abs(b[i])>abs(b[pos]) && b[i] != 0) pos = i;
        }
        if(b[pos]>0)
            res += b[pos]*k;
        else
            res -= b[pos]*k;
        printf("%lld\n", res);
    }
    return 0;
}


