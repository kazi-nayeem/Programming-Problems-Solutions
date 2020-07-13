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

#define MX 7005
#define inf 100000000

const ll mod = 1000000007ll;

int dp[MX][MX][2][2][2];
int n;
vector<int> adj[2];

int func(int st, int pos, int stp, int p, int sz) {
    if(pos == 0) {
        return 0;
    }
    if(st == pos && stp == p && sz == 1) return 2;
    int & res = dp[st][pos][stp][p][sz];
    if(res != -1) return res;
    res = 0;
    int cnt = 0;
    for(int i = 0; i < adj[p].size(); i++) {
        int tem = func(st,(pos+adj[p][i])%n,stp,p^1,1);
        if(tem == 0) {
            res = 1;
            //printf("%d %d %d %d\n", pos, p, sz, res);
            return res;
        }
        if(tem == 2) cnt++;
        else {
            tem = func(pos,(pos+adj[p][i])%n,p,p^1,1);
            if(tem == 2) cnt++;
        }
    }
    if(cnt) res = 2;
   // printf("%d %d %d %d\n", pos, p, sz, res);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp,-1,sizeof dp);
    scanf("%d", &n);
    for(int i = 0; i < 2; i++) {
        int k, x;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &x);
            adj[i].push_back(x);
        }
    }
    printf("%d\n", func(n-1,n-1,0,0,0));
    //printf("%d\n", func(1,1,1,1,0));
    //return 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < n; j++) {
            int ans = func(j,j,i,i,0);
            if(ans == 1)
                printf("Win ");
            else if(ans == 2)
                printf("Loop ");
            else
                printf("Lose ");
        }
        puts("");
    }
    return 0;
}

