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

ll arr[MX];

ll func(int n, ll siz) {
    if(siz == 0) return mod*1000;

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll tem = arr[i]%siz;
        ll need = (arr[i]+siz-1)/siz;
        if(tem > 0){
            tem = siz-tem-1;
        }
        if(need > tem) {
            ans += need;
        } else {
            return mod*10000;
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", &arr[i]);
    }
    sort(arr+1,arr+n+1);

    ll ans = func(n,1);
    for(ll i = 1; i*i<= arr[1]; i++)
    {
        //ans = min(ans,func(n,i));
        ans = min(ans,func(n,i+1));
        //ans = min(ans,func(n,i-1));
        ans = min(ans,func(n,arr[1]/i));
        //ans = min(ans,func(n,mini/i-1));
        ans = min(ans,func(n,arr[1]/i+1));
    }
    printf("%I64d\n", ans);
    return 0;
}

