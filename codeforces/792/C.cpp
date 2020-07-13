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

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

int dp[MX][3][2];
char str[MX];
int len;

int func(int pos, int m, int f) {
    if(pos == len) {
        if(m == 0) return 0;
        return -inf;
    }
    int & res = dp[pos][m][f];
    if(res != -1) return res;
    res = func(pos+1,(m+str[pos]-'0')%3,f || (str[pos]>'0'))+(str[pos]>'0' || f);
    res = max(res, func(pos+1,m,f));
    return res;
}
void print(int pos, int m, int f) {
    if(pos == len) {
        return;
    }

    int tem1 = func(pos+1,(m+str[pos]-'0')%3,f || (str[pos]>'0'))+(str[pos]>'0' || f);
    if(tem1 == func(pos,m,f) && (str[pos]>'0' || f)) {
        printf("%c", str[pos]);
        print(pos+1,(m+str[pos]-'0')%3,f || (str[pos]>'0'));
        return;
    }
    print(pos+1,m,f);
    return ;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp,-1,sizeof dp);
    scanf("%s", str);
    len = strlen(str);
    //printf("%d\n", func(0,0,0));
    if(func(0,0,0)<=0) {
        for(int i = 0; i < len; i++) {
            if(str[i] == '0') {
                puts("0");
                return 0;
            }
        }
        puts("-1");
        return 0;
    }
    print(0,0,0);
    return 0;
}

