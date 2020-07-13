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
int xx[] = {0,0,-1,1};
int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 1005
#define inf 100000000

const ll mod = 1000000007ll;

struct data {
    int x, y, d;
    data() {}
    data(int x, int y, int d): x(x), y(y), d(d) {}
};

char str[MX][MX];
int dp[MX][MX][4];
int row, col;

int dfs(int x, int y) {
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            for(int k = 0; k < 4; k++)
                dp[i][j][k] = mod;
        }
    queue<data> qu;
    for(int i = 0; i < 4; i++) {
        dp[x][y][i] = 0;
        qu.push(data(x,y,i));
    }
    while(!qu.empty()) {
        x = qu.front().x;
        y = qu.front().y;
        int d = qu.front().d;
        qu.pop();
        if(str[x][y] == 'T' && dp[x][y][d] <= 2) return 1;
        for(int i = 0; i < 4; i++) {
            int tx = x+xx[i];
            int ty = y+yy[i];
            if(tx< 0 || ty < 0 || tx >= row || ty >= col) continue;
            if(str[tx][ty] == '*') continue;
            int cost = dp[x][y][d]+(i!=d);
            if(dp[tx][ty][i] <= cost) continue;
            dp[tx][ty][i] = cost;
            qu.push(data(tx,ty,i));
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &row, &col);
    for(int i = 0; i < row; i++)
        scanf(" %s", str[i]);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            if(str[i][j] == 'S') {
                if(dfs(i,j))
                    puts("YES");
                else
                    puts("NO");
                return 0;
            }
        }
    return 0;
}


