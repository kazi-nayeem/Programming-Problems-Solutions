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

#define MX 105
#define inf 100000000

const ll mod = 1000007ll;

char str[MX][MX];
int n, len;

bool check(int pos1, int a, int pos2)
{
    for(int i = 0; i < len; i++)
    {
        if(str[0][(pos1+i)%len] != str[a][(pos2+i)%len]) return false;
    }
    return true;
}

int func(int pos)
{
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(check(pos,i,j))
            {
                res += j;
                break;
            }
            if(j+1 == len) return mod;
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %s", str[i]);
    len = strlen(str[0]);
    int res = mod;
    for(int i = 0; i < len; i++)
    {
        res = min(res,func(i));
    }
    if(res == mod) res = -1;
    printf("%d\n", res);
    return 0;
}

