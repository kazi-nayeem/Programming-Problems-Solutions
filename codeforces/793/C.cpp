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
const double eps = 1e-8;

struct frac{
    ll x, y;
    frac(){}
    frac(ll a, ll b)
    {
        ll gcd = __gcd(a,b);
        x = a/gcd;
        y = b/gcd;
    }
    bool operator < (const frac & p) const
    {
        return x*p.y<p.x*y;
    }
    bool operator <= (const frac & p) const
    {
        return x*p.y<=p.x*y;
    }
    void print()
    {
        printf("%lf\n", (double) x/y);
    }
};

frac tim1[MX];
frac tim2[MX];

bool func(ll rx, ll ry, ll vx, ll vy, ll x1, ll y1, ll y2, frac & tem) {
    if(vx == 0) return false;
    frac ti = frac((x1-rx),vx);
    if((((x1-rx)*vy+ry*vx)>=(y1*vx)) && (((x1-rx)*vy+ry*vx)<=(y2*vx))) {
        tem = ti;
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll x1, x2, y1, y2;
    ll rx, vx, ry, vy;
    scanf("%d %lld %lld %lld %lld", &n, &x1, &y1, &x2, &y2);
    frac rangx = frac(-mod,1);
    frac rangy = frac(mod,1);
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld %lld", &rx, &ry, &vx, &vy);
        tim1[i] = frac(mod,1);
        tim2[i] = frac(-mod,1);
        frac res;
        if(func(rx,ry,vx,vy,x1,y1,y2,res)) {
            tim1[i] = min(tim1[i],res);
            tim2[i] = max(tim2[i],res);
   //         puts("ok1");
        }
        if(func(rx,ry,vx,vy,x2,y1,y2,res)) {
            tim1[i] = min(tim1[i],res);
            tim2[i] = max(tim2[i],res);
     //       puts("ok2");
        }
        if(func(ry,rx,vy,vx,y1,x1,x2,res)) {
            tim1[i] = min(tim1[i],res);
            tim2[i] = max(tim2[i],res);
       //     puts("ok3");
        }
        if(func(ry,rx,vy,vx,y2,x1,x2,res)) {
            tim1[i] = min(tim1[i],res);
            tim2[i] = max(tim2[i],res);
         //   puts("ok4");
        }
        printf("%d>>\n", i);
        tim1[i].print();
        tim2[i].print();
        rangx = max(rangx,tim1[i]);
        rangy = min(rangy,tim2[i]);
    }
    //printf("%lf %lf\n", rangx, rangy);
    if(rangx<=rangy && rangy.x>=0) {
        printf("%.10lf\n", max( (double) rangx.x/rangx.y,0.0));
    } else {
        printf("-1\n");
    }
    return 0;
}


