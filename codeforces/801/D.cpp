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

#define PI acos(-1.0)

using namespace std;

const double INF = 1e100;
const double EPS = 1e-9;

int EQ(double x) {
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const {
        return PT(x/c,   y/c  );
    }
};

double dot(PT p, PT q) {
    return p.x*q.x+p.y*q.y;
}
double dist2(PT p, PT q) {
    return dot(p-q,p-q);
}
double distPoint(PT p, PT q) {
    return sqrt(dot(p-q,p-q));
}
double cross(PT p, PT q) {
    return p.x*q.y-p.y*q.x;
}

double distToLine(PT p, PT A, PT B, PT &c) {
    double scale = (double)
                   (dot(p-A,B-A)) /
                   (dot(B-A,B-A));
    c.x = A.x + scale * (B.x - A.x);
    c.y = A.y + scale * (B.y - A.y);
    return distPoint(p, c);
}

double distToLineSegment(PT p, PT A, PT B, PT &c) {
    if (dot(B-A,p-A) < EPS) {
        c.x = A.x;
        c.y = A.y;
        return distPoint(p, A);
    }
    if (dot(A-B,p-B) < EPS) {
        c.x = B.x;
        c.y = B.y;
        return distPoint(p, B);
    }
    return distToLine(p, A, B, c);
}

PT arr[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &arr[i].x, &arr[i].y );
    }
    double res = 1e15;
    for(int i = 0; i < n; i++) {
        PT tem;
        res = min(res, distToLineSegment(arr[(i+1)%n],arr[i],arr[(i+2)%n],tem));
    }
    printf("%.10lf\n", res/2.0);
    return 0;
}

