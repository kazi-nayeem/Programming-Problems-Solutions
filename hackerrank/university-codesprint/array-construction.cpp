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

int cs_dp[55][205][2005];
bool dp[55][205][2005];
int n, cas;

bool func(int baki, int s, int k) {
    if(baki == 0) {
        if(s == 0 && k == 0) return true;
        return false;
    }
    bool & res = dp[baki][s][k];
    int & test = cs_dp[baki][s][k];
    if(test == cas) return res;
    res = false;
    test = cas;
    res = func(baki-1,s,k);
    if(res) return res;
    int tk = n-baki;
    if(tk*baki<=k && baki <= s)
        res = func(baki,s-baki,k-tk*baki);
    return res;
}

int arr[200];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q, s, k;
    cas = 1;
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d %d", &n, &s, &k);
        cas++;
        if(!func(n,s,k)) {
            puts("-1");
            continue;
        }
        //puts("yes");
        memset(arr,0,sizeof arr);

        for(int i = 1; i <= n;) {
            if(func(n-i,s,k)) i++;
            else {
                s -= n-i+1;
                k -= (i-1)*(n-i+1);
                arr[i]++;
            }
        }
        printf("%d", arr[1]);
        for(int i = 2; i <= n; i++) {
            arr[i] += arr[i-1];
            printf(" %d", arr[i]);
        }
        puts("");
    }
    return 0;
}


