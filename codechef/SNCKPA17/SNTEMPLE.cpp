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

int arr[MX];
int pre[MX];
int nxt[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        ll tot = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            tot += arr[i];
            arr[i] = min(arr[i],i);
            arr[i] = min(arr[i],n-i+1);
        }
        arr[n+1] = 0;
        arr[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(arr[i]>arr[i-1])
                pre[i] = pre[i-1]+1;
            else{
                pre[i] = min(pre[i-1]+1,arr[i]);
            }
        }
        for(int i = n; i > 0; i--)
        {
            if(arr[i]>arr[i+1])
                nxt[i] = nxt[i+1]+1;
            else{
                nxt[i] = min(nxt[i+1]+1,arr[i]);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans,min(pre[i],nxt[i]));
        }
        tot -= (ll) ans*(ans+1ll)/2ll + (ans-1ll)*ans/2ll;
        printf("%lld\n", tot);
    }
    return 0;
}


