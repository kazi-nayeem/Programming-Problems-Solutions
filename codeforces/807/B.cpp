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

int funcpos(int i, int p)
{
    for(int j = 0; j < 25; j++)
    {
        i = (i*96+42)%475;
        if(i+26 == p) return 1;
    }
    return 0;
}

int flag[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p, x, y;
    scanf("%d %d %d", &p, &x, &y);
    for(int i = 0; i < 475; i++)
    {
        if(funcpos(i,p)) flag[i] = 1;
    }
    int ans = mod;
    for(int i = 0; i+x>= y; i-= 50)
    {
        int s = i+x;
        s /= 50;
        if(flag[s%475] == 1)
        {
            ans = 0;
            //puts("ok");
            break;
        }
    }
    if(ans != 0)
    {
        for(int i = 0; i>=0; i+=50)
        {
            int s = i+x;
            s /= 50;
            if(flag[s%475] == 1)
            {
                ans = (i+50)/100;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


