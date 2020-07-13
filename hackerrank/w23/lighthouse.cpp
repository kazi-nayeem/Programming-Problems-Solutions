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

int sqr(int a)
{
    return a*a;
}

int dissqr(int x1, int y1, int x2, int y2)
{
    return sqr(x1-x2)+sqr(y1-y2);
}

char str[100][100];

bool check(int x, int y, int r)
{
    for(int i = x-r; i <= x+r; i++)
        for(int j = y-r; j <= y+r; j++)
        {
            if(dissqr(x,y,i,j)<=r*r)
            {
                if(str[i][j] != '.') return false;
            }
        }
    return true;
}

int find_mx(int x, int y, int mx)
{
    for(int i = 0; i <= mx; i++)
    {
        if(!check(x,y,i)) return i-1;
    }
    return mx;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %s", str[i]);
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            res = max(res,find_mx(i,j,min(min(i,n-1-i),min(j,n-1-j))));
        }
    printf("%d\n", res);
    return 0;
}


