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

int LCM(int a, int b)
{
    if(a == 0) return b;
    return a*b/__gcd(a,b);
}

vector<int> mat[MX];

void func(int pos, int mask, int lcm)
{
    if(pos == 10)
    {
        if(mask>0)
        mat[lcm].push_back(mask);
        return;
    }
    func(pos+1,mask,lcm);
    func(pos+1,mask | (1<<pos), LCM(pos,lcm));
}

ll dp[1<<10][20][2][2][2525];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    func(0,0,1);
    for(int i = 0; i < MX; i++)
    {
        if(mat[i].size() == 0) continue;
        printf("%d->", i);
        for(int j = 0; j < mat[i].size(); j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
    return 0;
}

