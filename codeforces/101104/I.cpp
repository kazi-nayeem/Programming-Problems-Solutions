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

int cnt[MX][MX];
int row[MX];
int col[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--)
    {
        memset(cnt,0,sizeof cnt);
        memset(row,0,sizeof row);
        memset(col,0,sizeof col);
        int n, x, y, d;
        scanf("%d %d", &d, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            x %= d;
            x += d;
            x %= d;
            y %= d;
            y += d;
            y %= d;
            cnt[x][y]++;
        }
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                row[i] += cnt[i][j];
                col[j] += cnt[i][j];
            }
        }
        int res = n+10;
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
                res = min(res,row[i]+col[j]-cnt[i][j]);
        printf("%d\n", res);
    }
    return 0;
}

