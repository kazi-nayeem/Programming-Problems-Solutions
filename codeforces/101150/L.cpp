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

ll total[MX];
int man[MX];
int nxt[MX];
int r, k, n;

void process() {
    int sum = man[0];
    int pos = 1%r;
    //puts("ok");
    for(int i = 0; i < r; i++) {
        while((pos != i || sum == 0) && sum+man[pos] <= k) {
            sum += man[pos];
            pos++;
            pos %= r;
        }
        total[i] = sum;
        nxt[i] = pos;
        sum -= man[i];
    }
//    puts("ok");
//    for(int i = 0; i < r; i++)
//        printf("%lld %d\n", total[i], nxt[i]);
}

int flag[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &k, &r);
    for(int i = 0; i < r; i++) {
        scanf("%d", &man[i]);
    }
    process();
    int i;
    for(i = 0; flag[i] == 0; i = nxt[i])
        flag[i] = 1;
    int rep = i;
   // printf("%d\n", i);
    ll res = 0;
    for(int i = 0; i != rep && n>0; i = nxt[i], n--)
        res += total[i];
    int stp = 1;
    ll cir = total[rep];
    for(int i = nxt[rep]; i != rep; i = nxt[i], stp++)
        cir += total[i];
    res += (n/stp)*cir;
    n %= stp;
    for(int i = rep; n>0; i = nxt[i], n--)
        res += total[i];
    printf("%lld\n", res);
    return 0;
}

