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

struct data {
    ll a, b;
    bool operator < (const data & p) const {
        return p.a*b<a*p.b;
    }
};

data arr[MX];

bool func(int n, double ti, int p) {
    double pre = 0.0;
    double total = 0.0;
    for(int i = 1; i <= n; i++) {
        double tm = (double) 1.0*arr[i].b/arr[i].a;
        if(arr[i].a > p) {
            double li = (double) 1.0*arr[i].b/(arr[i].a-p);
            if(li<ti) return false;
        }
        total += max(0.0, (ti-tm)*arr[i].a);
    }
    return total<=ti*p;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, p;
    ll tot = 0, tot2 = 0;
    scanf("%d %d", &n, &p);
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld", &arr[i].a, &arr[i].b);
        tot += arr[i].a;
        tot2 += arr[i].b;
    }
    if(tot<=p) {
        puts("-1");
        return 0;
    }

    double low = 0.0, hi = 1e16;
    for(int i = 0; i < 100; i++) {
        double mid = (low+hi)/2.0;
        if(func(n,mid,p))
            low = mid;
        else
            hi = mid;
    }
    printf("%.8lf\n", low);
    return 0;
}

