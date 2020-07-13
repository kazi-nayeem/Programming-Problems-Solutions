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

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

string res[MX];
string tem[MX];
int pos = 1;

string getNew() {
    return tem[pos++];
}

int flag[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        if(i <= 26) {
            char ch[10];
            ch[0] = i+'A'-1;
            ch[1] = 0;
            tem[i] = ""+(string) ch;
        } else {
            char ch[10];
            ch[0] = i+'a'-27;
            ch[1] = 0;
            tem[i] = "A"+(string) ch;
        }
        //cout<<res[i]<<endl;
    }
    int now = 1;
    for(int i = 1; i <= n-k+1; i++) {
        char str[100];
        scanf("%s", str);
        if(str[0] == 'Y') {
            for(; now<=i+k-1; now++)
                res[now] = getNew();
        } else {
            if(now == 1) {
                res[now] = getNew();
                now++;
            }
            res[now] = res[i];
            now++;
        }
    }
    while(now<=n) {
        res[now] = getNew();
        now++;
    }
    for(int i = 1; i <= n; i++)
        cout<<res[i]<<" ";
    return 0;
}

