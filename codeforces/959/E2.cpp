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
#include<complex>
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

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

ll total[MX];
ll last[MX];


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    total[1] = 1;
    last[1] = 1;
    for(int i = 2; i <= 50; i++)
    {
        last[i] = last[i-1]*2;
        total[i] = total[i-1]*2+last[i-1];
        //printf("%d %lld\n", i, total[i]);
    }
    ll n, ans = 0;
    scanf("%lld", &n);
    n--;
    int pos = 1;
    while(n>0)
    {
        //printf("%lld\n", n);
        if(n%2 == 1)
        {
            ans += total[pos];
        }
        n /= 2;
        pos++;
    }
    printf("%lld\n", ans);

    return 0;
}


