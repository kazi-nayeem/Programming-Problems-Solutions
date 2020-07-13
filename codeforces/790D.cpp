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

#define MX 300105
#define inf 100000000

const ll mod = 1000000007ll;

struct data {
    int a, b;
    data() {}
    data(int aa, int bb) {
        a = aa;
        b = bb;
    }
};

ll arr[MX][2];
int nextt[MX][3];
vector<data> seg[3];
map<ll,int> mp;
int n;

int func(int i, int j) {
    //printf("%d %d\n", i, j);
    if((i >= n+1) && (j >= n+1)) {
        return 0;
    }
    if(nextt[i][0] <= nextt[j][1]) {
        if(nextt[i][0] <= nextt[max(i,j)][2]) {
            return func(nextt[i][0]+1,j)+(nextt[i][0]<=n);
        } else {
            return func(nextt[max(i,j)][2]+1, nextt[max(i,j)][2]+1)+(nextt[max(i,j)][2]<=n);
        }
    } else {
        if(nextt[j][1] <= nextt[max(i,j)][2]) {
            return func(i,nextt[j][1]+1)+(nextt[j][1]<=n);
        } else {
            return func(nextt[max(i,j)][2]+1, nextt[max(i,j)][2]+1)+(nextt[max(i,j)][2]<=n);
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int j = 0; j < 2; j++)
        for(int i = 1; i <= n; i++) {
            scanf("%I64d", &arr[i][j]);
            arr[i][j] += arr[i-1][j];
        }
    for(int i = n+1; i <= 50+n; i++)
    {
        for(int j = 0; j < 3; j++)
            nextt[i][j] = i;
    }
    for(int j = 0; j < 2; j++) {
        mp.clear();
        for(int i = n; i > 0; i--) {
            mp[arr[i][j]] = i;
            if(mp.find(arr[i-1][j]) != mp.end()) {
                int last = mp[arr[i-1][j]];
                nextt[i][j] = last;
                seg[j].push_back(data(i,last));
            } else
                nextt[i][j] = n+1;
            nextt[i][j] = min(nextt[i][j],nextt[i+1][j]);
        }
    }
    mp.clear();
    for(int i = n; i > 0; i--) {
        mp[arr[i][0]+arr[i][1]] = i;
        if(mp.find(arr[i-1][0]+arr[i-1][1]) != mp.end()) {
            int last = mp[arr[i-1][0]+arr[i-1][1]];
            nextt[i][2] = last;
            seg[2].push_back(data(i,last));
        } else
            nextt[i][2] = n+1;
        nextt[i][2] = min(nextt[i][2],nextt[i+1][2]);
    }
//    for(int j = 0; j < 3; j++) {
//        for(int i = 0; i <= n; i++)
//            printf("%d ", nextt[i][j]);
//        printf("\n");
//    }
    printf("%d\n", func(1,1));
    return 0;
}


