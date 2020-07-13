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

vector<int> adj[MX];
int cnt[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        int n, k, x, p;
        scanf("%d %d", &n, &k);
        memset(cnt,0,sizeof cnt);
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            scanf("%d", &p);
            while(p--)
            {
                scanf("%d", &x);
                adj[i].push_back(x);
                cnt[x]++;
            }
        }
        bool flag = false;
        for(int i = 1; i <= k; i++)
        {
            if(cnt[i] == 0){
                flag = true;
                break;
            }
        }
        if(flag)
        {
            puts("sad");
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            flag = true;
            for(int j = 0; j < adj[i].size(); j++)
            {
                if(cnt[adj[i][j]] <= 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag)
            puts("some");
        else
            puts("all");
    }
    return 0;
}


