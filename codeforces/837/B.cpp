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

const ll mod = 1000000007ll;

char str[MX][MX];
char str2[MX][MX];

bool func(int n, int m)
{
    if(n%3) return false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
            if(str[i][j] != str[i][j-1]) return false;
    }
    vector<int> res;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(str[i][0] == str[i-1][0]) cnt++;
        else
        {
            res.push_back(cnt);
            cnt = 1;
        }
    }
    res.push_back(cnt);
    //puts("ok");
    if(res.size() != 3) return false;
    for(int i = 1; i < 3; i++)
        if(res[i] != res[i-1]) return false;
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf(" %s", str[i]);
    if(func(n,m))
    {
        puts("YES");
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            str2[j][i] = str[i][j];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            str[i][j] = str2[i][j];
    if(func(m,n))
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}

