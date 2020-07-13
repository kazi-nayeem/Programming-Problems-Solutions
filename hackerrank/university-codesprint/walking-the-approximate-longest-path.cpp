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
#include <random>
#include <ctime>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 50000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

vector<int> adj[MX];
int flag[MX];
int res[MX];
int tem[MX];
int siz;
int n, m;
int count_walk;

void back_track(int u, int tk) {
    if(count_walk>inf) return;
    count_walk++;
    int v;
    tem[tk] = u;
    flag[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        v = adj[u][i];
        if(flag[v]) continue;
        back_track(v,tk+1);
        if(siz == n) break;
        if(count_walk>inf) break;
    }
    if(tk>siz) {
        siz = tk;
        for(int i = 1; i <= siz; i++)
            res[i] = tem[i];
    }
    flag[u] = 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    srand(time(NULL));

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    back_track((((rand()%n)+n)%n) + 1,1);
    printf("%d\n%d", siz, res[1]);
    for(int i = 2; i <= siz; i++)
        printf(" %d", res[i]);
    puts("");
    return 0;
}


