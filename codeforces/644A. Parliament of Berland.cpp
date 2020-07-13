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

int arr[1000][1000];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if(n > a*b) {
        puts("-1");
        return 0;
    }
    int ti = 0;
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++) {
            if(n<=ti) break;
            ti++;
            if(i%2 == 0) {
                arr[i][j] = ti;
            } else {
                arr[i][b-j-1] = ti;
            }
        }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++)
            printf("%d%c", arr[i][j], (j == b-1)? '\n':' ');
    }
    return 0;
}

