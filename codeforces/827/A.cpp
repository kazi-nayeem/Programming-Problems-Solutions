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

#define MX 2000005
#define inf 100000000

const ll mod = 1000000007ll;

char ans[MX];
char str[MX];

int nxt[MX];

int find_nxt(int i)
{
    if(nxt[i] == i) return i;
    return nxt[i] = find_nxt(nxt[i]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < MX; i++)
        nxt[i] = i;
    int n;
    scanf("%d", &n);
    for(int j = 1; j <= n; j++)
    {
        scanf("%s", str);
        int len = strlen(str);
        int p, x;
        scanf("%d", &p);
        while(p--)
        {
            scanf("%d", &x);
            x--;
            for(int i = 0; i < len; i = find_nxt(x+i)-x)
            {

                int pos = find_nxt(i+x);
                //printf("%d %d\n", i, pos, i+x);
                if(pos == i+x)
                {
                    ans[i+x] = str[i];
                    nxt[i+x] = i+x+1;
                }
            }
        }
    }
    bool flag = false;
    for(int i = MX-2; i >= 0; i--)
    {
        if(ans[i] != 0)
        {
            flag = true;
            continue;
        }
        if(flag) ans[i] = 'a';
    }
    puts(ans);
    return 0;
}


