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

struct data {
    int x, y;
    bool operator < (const data & p) const {
        return y<p.y;
    }
};

data arr[MX];
int flag;

int func(int low, int hi, int n, int k) {
    deque<int> qu;
    int res = inf;
    for(int i = 0; i < n; i++) {
        if(arr[i].x >= low && arr[i].x <= hi) {
            qu.push_back(arr[i].y);
            while(qu.size()>k) qu.pop_front();
            if(qu.size()>=k) {
                flag = 1;
                res = min(res,qu.back()-qu.front());
            }
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, n;
    scanf("%d", &ti);
    while(ti--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &arr[i].x, &arr[i].y);
        }
        sort(arr,arr+n);
        ll res = mod*mod;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++) {
                flag = 0;
                ll tem = func(min(arr[i].x,arr[j].x),max(arr[i].x,arr[j].x),n,(n+1)/2);
                if(flag)
                    res = min(res,abs(arr[i].x-arr[j].x)*tem);
            }
        printf("%I64d\n", res);
    }
    return 0;
}

