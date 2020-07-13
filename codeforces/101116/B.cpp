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

#define MX 405
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int arr[MX][MX];
int cnt[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n, m;
    scanf("%d", &ti);
    while(ti--) {
        scanf("%d %d", &n, &m);
        //puts("ok");
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%1d", &arr[i][j]);
            }
        }
        int ans = 0;
        memset(cnt,0,sizeof cnt);
        for(int i = 1; i <= n; i++) {
            int pre = 0;
            for(int j = m; j >= 1; j--) {
                //printf("%d %d %d\n", j, cnt[j], pre);
                if(((cnt[j]+arr[i][j]+pre)%2) == 0) {
                    pre++;
                    cnt[j]++;
                    ans++;
                }
            }
            //puts("");
        }
        printf("%d\n", ans);
    }
    return 0;
}

