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

char str[2][MX];
int cnt[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        scanf("%s %s", str[0], str[1]);
        int prev = 3;
        for(int i = 0; i < n; i++)
        {
            if(str[0][i] == '#' && str[1][i] == '#')
            {
                prev = ((prev&1)<<1) | (prev>>1);
                cnt[i] = 2;
            }
            else if(str[0][i] == '#')
            {
                prev = prev&1;
                cnt[i] = 1;
            }
            else if(str[1][i] == '#')
            {
                prev = prev&(1<<1);
                cnt[i] = 1;
            }
            else
            {
                cnt[i] = 0;
            }
        }
        bool ans = true;
        int flag = 0;
        for(int i = 0; i < n && ans; i++)
        {
            if(cnt[i])
            {
                if(flag == 2) ans = false;
                else flag = 1;
            }
            else if(flag)
            {
                flag = 2;
            }
        }
        if(ans && prev)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}


