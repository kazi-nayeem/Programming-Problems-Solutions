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

int k;

vector<int> vc;
vector<int> newvc;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, n, x, a;
    scanf("%d", &ti);
    while(ti--) {
        scanf("%d %d", &n, &k);
        vc.clear();
        vc.push_back(0);
        for(int i = 0; i < n; i++) {
            newvc.clear();
            int x;
            scanf("%d", &x);
            while(x--) {
                scanf("%d", &a);
                for(int j = 0; j < vc.size(); j++) {
                    newvc.push_back(vc[j]+a);
                }
            }
            sort(newvc.begin(), newvc.end());
            vc.clear();
            for(int j = 0; j < min(k,(int) newvc.size()); j++) {
                vc.push_back(newvc[j]);
            }
        }
        printf("%d", vc[0]);
        for(int i = 1; i < vc.size(); i++)
            printf(" %d", vc[i]);
        puts("");
    }
    return 0;
}

