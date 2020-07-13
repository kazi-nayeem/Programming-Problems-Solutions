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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

queue<int> qu;

queue<int> arr[MX];

int flag[MX], m, c;

void init() {
    memset(flag,-1,sizeof flag);
    for(int i = 0; i <= 100; i++)
        flag[i+m*c] = i;
}

int find_pos(int k) {
    for(int i = 0; i < MX; i++)
        if(flag[i] == k) return i;
    return -1;
}

int find_free() {
    for(int i = 0; i < MX; i++)
        if(flag[i] == -1) return i;
    return -1;
}

int calc(int p) {
    return min(m,p/c)+1;
}

int cost(int k) {
    int pos = find_pos(k);
    int ans = calc(pos);
    while(pos+1<c) {
        flag[pos] = flag[pos+1];
        pos++;
    }
    flag[pos] = -1;
    int fre1 = find_free();
    ans += calc(fre1);
    if(fre1<c) {
        for(int i = c-1; i > 0; i--)
            flag[i] = flag[i-1];
        flag[0] = k;
        return ans;
    }
    flag[fre1] = k;
    int fr2 = find_free();
    ans += calc(fr2)+1+calc(fre1)+1;
    flag[fr2] = flag[c-1];
    flag[fre1] = -1;
    for(int i = c-1; i > 0; i--)
        flag[i] = flag[i-1];
    flag[0] = k;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d %d %d", &m, &c, &n) == 3) {
        if(n == 0 && m == 0 && c == 0) return 0;
        for(int i = 0; i < n; i++) {
            int x, p;
            scanf("%d", &p);
            while(p--) {
                scanf("%d", &x);
                arr[i].push(x);
            }
        }
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < n; i++) {
                if(arr[i].empty()) continue;
                qu.push(arr[i].front());
                arr[i].pop();
                flag = true;
            }
        }
        init();
        int res = 0;
        while(!qu.empty()) {
            //printf("%d", qu.front());
            res += cost(qu.front());
            //printf("----%d\n", res);
            qu.pop();
        }
        printf("%d\n", res);
    }
    return  0;
}

