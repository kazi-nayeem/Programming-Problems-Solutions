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

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

int arr[MX];
int pre[MX];
int nxt[MX];

map<int,int> mp;

int main() {
    int n;
    ll ans = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        pre[i] = pre[i-1] ^ arr[i];
    }
    pre[n+1] = pre[n];
    for(int i = n; i >= 0; i--)
    {
        nxt[i] = nxt[i+1]^arr[i];
    }
    mp[0] = 1;
    for(int i = 1; i <= n; i++) {

        int need = pre[n]^pre[i];
        ans += mp[need];
        mp[pre[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}


