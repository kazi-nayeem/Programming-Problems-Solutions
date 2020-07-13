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

map<char,int> mp;
char str[100][100];
int arr[100][100];

int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};
int cellcnt;

int func(int x, int y, int n) {
    if(x < 0 || x >= n || y < 0 || y >= n) return 0;
    //printf(">>>%d %d %d %d\n", x, y,arr[x][y], 1<<arr[x][y]);
    if(arr[x][y] != 5) return 1<<arr[x][y];
    arr[x][y] = 0;
    cellcnt++;
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int xt = x+xx[i];
        int yt = y+yy[i];
        cnt |= func(xt,yt,n);
    }
    return cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    mp['.'] = 1;
    mp['B'] = 2;
    mp['P'] = 3;
    mp['G'] = 4;
    mp['?'] = 5;
    int q, n;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf(" %s", str[i]);
            for(int j = 0; j < n; j++) {
                arr[i][j] = mp[str[i][j]];
            }
        }
//        for(int i = 0; i < n; i++, puts(""))
//            for(int j = 0; j < n; j++) {
//                printf("%d ", arr[i][j]);
//            }
        ll ans = 1;
        for(int i = 0; i < n && ans; i++)
            for(int j = 0; j < n && ans; j++) {
                if(arr[i][j] != 4) continue;
                for(int k = 0; k < 4 && ans; k++) {
                    int x = i+xx[k];
                    int y = j+yy[k];
                    if(x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if(arr[x][y] != 1) {
                        ans = 0;
                    }
                }
            }
        for(int i = 0; i < n && ans; i++) {
            for(int j = 0; j < n && ans; j++) {
                if(arr[i][j] != 5) continue;
                cellcnt = 0;
                int cnt = func(i,j,n);
                //printf("%d %d %d\n", i, j, cnt);
                if((cnt>>4) & 1) {
                    ans = 0;
                } else if(((cnt>>2)&3) == 3) {
                    ans = 0;
                } else if(((cnt>>2)&3) == 0) {
                    ans *= 2+(cellcnt == 1);
                }
                ans %= mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}


