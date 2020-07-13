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

#define MX 10505
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

double time_need[MX];

int n;
int arr[200];
double b;

int cas, mx;
int csdp[200];
double dp[200];

double func(int p) {
    if(p == n) return 0.0;
    double & res = dp[p];
    int & c = csdp[p];
    if(c == cas) return res;
    c = cas;
    res = inf;
    for(int i = p+1; i <= n; i++) {
        res = min(res,func(i)+time_need[arr[i]-arr[p]]+b);
    }
    //printf("%d %lf\n", arr[p], res);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%lf", &b);
        int r;
        double v, e, f;
        scanf("%d %lf %lf %lf", &r, &v, &e, &f);
        time_need[0] = 0.0;
        for(int i = 1; i <= arr[n]; i++) {
            if(i <= r) time_need[i] = (double) 1.0/(v-(f*(r-i+1)));
            else time_need[i] = (double) 1.0/(v-(e*(i-1-r)));
            time_need[i] += time_need[i-1];
            //printf("--->%d %lf\n", i, time_need[i]);
        }
        cas++;
        arr[0] = 0;
        printf("%lf\n", func(0)-b);
    }
    return 0;
}

