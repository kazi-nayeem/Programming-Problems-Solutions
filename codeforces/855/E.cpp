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

ll dp[12][1<<10][70][2][2];
int cs_dp[12][1<<10][70][2][2];
int cas;
int arr[100];

ll func2(int b, int mask, int p, int eq, int ze)
{
    if(p == 0)
    {
        if(mask == 0) return 1;
        return 0;
    }
    ll & res = dp[b][mask][p][eq][ze];
    int & cs_res = cs_dp[b][mask][p][eq][ze];
    if(eq == 0 && cs_res != 0) cs_res = cas;
    if(cs_res == cas) return res;
    res = 0;
    int hi = (eq)? arr[p]:b-1;
    for(int i = 0; i <= hi; i++)
    {
        if(ze || i>0)
            res += func2(b,mask^(1<<i),p-1, eq && i == hi, 1);
        else
            res += func2(b,mask,p-1, eq && i == hi, 0);
    }
    return res;
}

ll func(int b, ll n)
{
    if(n == 0) return 1;
    int len = 0;
    //printf(">>>>");
    while(n>0)
    {
        len++;
        arr[len] = n%b;
        n /= b;
        //printf("%d", arr[len]);

    }
    //puts("");
    cas++;
    return func2(b,0,len,1,0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int b;
        ll l, r;
        scanf("%d %lld %lld", &b, &l, &r);
//        for(int i = 1; i <= r; i++)
//            printf("%d %lld\n", i, func(b,i));
        //printf("%lld\n", func(b,l-1));
        //printf("%lld\n", func(b,r));
        printf("%lld\n", func(b,r)-func(b,l-1));
    }
    return 0;
}

