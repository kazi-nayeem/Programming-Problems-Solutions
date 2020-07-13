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

ll arr1[MX];
ll arr2[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &arr1[i]);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &arr2[i]);
    ll sum1 = 0, sum2 = 0;
    ll a = 0, b = 0;
    for(int i = 1; i <= n; i++)
    {
        sum1 += arr1[i];
        sum2 += arr2[i];
        ll make = max(arr1[i], arr2[i]);
        if((make-arr1[i])%2 == 1) make++;
        ll aa = (make-arr1[i])/2;
        ll bb = (make-arr2[i]);
        ll mi = min(aa,bb);
        aa -= mi;
        bb -= mi;
        mi = min(aa,b);
        aa -= mi;
        b -= mi;
        mi = min(a,bb);
        a -= mi;
        bb -= mi;

        a += aa;
        b += bb;
    }
    printf("%lld %lld\n", a, b);
    if(a == b)
        puts("Yes");
    else
        puts("No");
    return 0;
}

