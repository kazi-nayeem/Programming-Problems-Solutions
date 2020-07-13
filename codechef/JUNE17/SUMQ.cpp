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

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

ll arr1[MX];
ll arr2[MX];
ll arr3[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, p, q, r;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d %d", &p, &q, &r);
        for(int i = 1; i <= p; i++)
            scanf("%lld", &arr1[i]);
        for(int i = 1; i <= q; i++)
            scanf("%lld", &arr2[i]);
        for(int i = 1; i <= r; i++)
            scanf("%lld", &arr3[i]);
        sort(arr1+1,arr1+1+p);
        sort(arr2+1,arr2+1+q);
        sort(arr3+1,arr3+1+r);
        ll pos1 = 0;
        ll pos3 = 0;
        ll sum1 = 0, sum3 = 0;
        ll ans = 0;
        for(int i = 1; i <= q; i++)
        {
            while(pos1<p && arr1[pos1+1]<=arr2[i])
            {
                pos1++;
                sum1 += arr1[pos1];
                sum1 %= mod;
            }
            while(pos3<r && arr3[pos3+1]<=arr2[i])
            {
                pos3++;
                sum3 += arr3[pos3];
                sum3 %= mod;
            }

            ll tem = (((pos1*pos3)%mod)*((arr2[i]*arr2[i])%mod))%mod;
            tem += (((pos3*sum1)%mod)*arr2[i])%mod;
            tem %= mod;
            tem += (((pos1*sum3)%mod)*arr2[i])%mod;
            tem %= mod;
            tem += (sum1*sum3)%mod;
            tem %= mod;
            ans = (ans+tem)%mod;
        }
        printf("%lld\n", ans);

    }
    return 0;
}


