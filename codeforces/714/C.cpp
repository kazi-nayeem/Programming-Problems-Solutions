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

map<int,int> mp;

int covert(ll a)
{
    int res = 0;
    int p = 0;
    while(a>0)
    {
        res += (a%2)<<p;
        p++;
        a /= 10;
    }
    return res;
}

char str[100];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll x;
    char ch;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &ch);
        if(ch == '+')
        {
            scanf("%lld", &x);
            mp[covert(x)]++;
        }
        else if(ch == '-')
        {
            scanf("%lld", &x);
            mp[covert(x)]--;
        }else{
            scanf(" %s", str);
            int len = strlen(str);
            int p = 0;
            for(int i = 0; i < len; i++)
            {
                p *= 2;
                p += str[i]-'0';
            }
            printf("%d\n", mp[p]);
        }
    }
    return 0;
}

