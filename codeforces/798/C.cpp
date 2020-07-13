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

ll arr[MX];

int func(int n, ll d) {
    int ans = 0;
    ll pre = 0;
    for(int i= 1; i <= n; i++) {
        pre += arr[i];
        if(pre%d == 0) {
            ans++;
            pre = 0;
        }
    }
    return n-ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll tot = 0;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        tot += arr[i];
    }
    vector<ll> divi;
    for(ll i = 2; i*i <= tot; i++) {
        if(tot%i != 0) {
            continue;
        }
        ///printf("ok");
        divi.push_back(i);
        while(tot%i == 0) tot/=i;
    }
    if(tot>1) divi.push_back(tot);
    int res = mod;
    for(int i = 0; i < divi.size(); i++) {
        res = min(res,func(n,divi[i]));
    }
    if(res == mod) {
        puts("NO");
        return 0;
    }
    printf("YES\n%lld\n", res);
    return 0;
}

