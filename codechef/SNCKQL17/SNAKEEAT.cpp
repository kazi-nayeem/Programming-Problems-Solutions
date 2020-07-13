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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q, ti;
    ll x;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        sort(arr+1,arr+1+n);
        sum[0] = 0ll;
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i-1]+arr[i];
        while(q--)
        {
            scanf("%lld", &x);
            int pos = lower_bound(arr+1,arr+n+1,x)-arr;
            int low = 1, hi = pos-1, ans = pos;
            while(low<=hi)
            {
                int mid = (low+hi)/2;
                ll tem = sum[pos-1]-sum[mid-1];
                if(tem+mid-1>=(pos-mid)*x)
                {
                    hi = mid-1;
                    ans = min(ans,mid);
                }else{
                    low = mid+1;
                }
            }
            printf("%d\n", n-ans+1);
        }
    }

    return 0;
}


