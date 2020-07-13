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

#define MX 100
#define inf 100000000

const ll mod = 1000000007ll;

char str[MX];

int dp[MX][MX][MX][2];

int len, cntv, cntk, cntx;
int vpos[MX];
int kpos[MX];
int xpos[MX];
int cnt[MX][3];

int func(int pos, int v, int k, int f) {
    //printf("%d %d %d %d\n", pos, v, k, f);
    if(len == pos) {
        if(cntv == v && k == cntk) return 0;
        //printf(">>>%d %d %d %d\n", pos, v, k, f);
        return inf;
    }
    //printf("%d %d %d %d\n", pos, v, k, f);
    int & res = dp[pos][v][k][f];
    if(res != -1) return res;
    res = inf;
    int x = pos-v-k;
    if(cntx>x)
        res = min(res,func(pos+1,v,k,0)+abs(cnt[xpos[x]][0]-v)+abs(cnt[xpos[x]][1]-k)+abs(cnt[xpos[x]][2]-x-1));
    if(cntv>v)
        res = min(res,func(pos+1,v+1,k,1)+abs(cnt[vpos[v]][0]-v-1)+abs(cnt[vpos[v]][1]-k)+abs(cnt[vpos[v]][2]-x));
    if(cntk>k && f == 0)
        res = min(res,func(pos+1,v,k+1,0)+abs(cnt[kpos[k]][0]-v)+abs(cnt[kpos[k]][1]-k-1)+abs(cnt[kpos[k]][2]-x));
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &len);
    scanf("%s", str);
    for(int i = 0; i < len; i++) {
        if(str[i] == 'V') {
            vpos[cntv++] = i;
            cnt[i][0] = 1;
        } else if(str[i] == 'K') {
            kpos[cntk++] = i;
            cnt[i][1] = 1;
        } else {
            xpos[cntx++] = i;
            cnt[i][2] = 1;
        }
    }
    xpos[cntx] = len;
    vpos[cntv] = len;
    kpos[cntk] = len;
    for(int i = 1; i <= len; i++) {
        for(int j = 0; j < 3; j++) {
            cnt[i][j] += cnt[i-1][j];
        }
    }
//    for(int i = 0; i <= len; i++) {
//        for(int j = 0; j < 3; j++) {
//            printf("%d ", cnt[i][j]);
//        }
//        puts("");
//    }
//    for(int i = 0; i < cntx; i++)
//        printf("X %d\n", xpos[i]);
//    for(int i = 0; i < cntv; i++)
//        printf("V %d\n", vpos[i]);
//    for(int i = 0; i < cntk; i++)
//        printf("K %d\n", kpos[i]);
    memset(dp,-1,sizeof dp);
    printf("%d\n", func(0,0,0,0)/2);
    return 0;
}

