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

ll arr[MX];
ll sum[MX];
ll start[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n;
    ll l, a, b;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %lld %lld %lld", &n, &l, &a, &b);
        ll totcost = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            if(arr[i]<a)
            {
                totcost += a-arr[i];
                arr[i] = a;
            }
            if(arr[i]>b-l)
            {
                totcost += arr[i]-b+l;
                arr[i] = b-l;
            }
            arr[i] -= a;
        }
        sort(arr+1,arr+n+1);
        for(int i = 1; i <= n; i++)
        {
            arr[i] = arr[i]-(i-1)*l;
        }
        sort(arr+1,arr+n+1);
        for(int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1]+arr[i];
        }
        ll ans = mod*mod;
        for(int i = 1; i <= n; i++)
        {
            //if(arr[i]<0) continue;
            //if(arr[i]+n*l>b-a) continue;
            ans = min(ans,arr[i]*i-sum[i]+sum[n]-sum[i]-arr[i]*(n-i));
        }
        printf("%lld\n", ans+totcost);
    }
    return 0;
}


