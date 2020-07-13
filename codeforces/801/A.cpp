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

char str[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(str);
    int len = strlen(str);
    int ans = 0;
    for(int i = 1; i < len; i++)
    {
        if(str[i] == 'K' && str[i-1] == 'V')
        {
            ans++;
            str[i] = '*';
            str[i-1] = '*';
        }
    }
    bool flag = true;
    for(int i = 0; i+1 < len && flag; i++)
    {
        if(str[i] == 'V' && str[i+1] != '*')
        {
            ans++;
            flag = false;
            break;
        }
    }
    for(int i = 1; i < len && flag; i++)
    {
        if(str[i] == 'K' && str[i-1] != '*')
        {
            ans++;
            flag = false;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}


