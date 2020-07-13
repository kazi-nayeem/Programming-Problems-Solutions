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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 1005005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    arr[0] = (-2)*mod;
    for(int i = 1; i <= 50; i++)
        arr[n+i] = (i+4)*mod;
    ll m, low, hi;
    scanf("%lld %lld %lld", &m, &low, &hi);
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i]-arr[i-1] <= low) continue;
        pos = max(pos,i);
        ll pre = min(hi,arr[i]-arr[i-1]-1);
        bool flag = false;
        while((arr[pos+1]-arr[i]+pre) < m)
        {
            if(((arr[pos+1]-arr[pos]) < low || (arr[pos+1]-arr[pos]) > hi))
            {
                flag = true;
                break;
            }
            pos++;
        }
        if(flag) continue;
        //printf("%d %d\n", i, pos);
        ll x = arr[pos]-m;
        if(x > arr[i-1] && arr[i]-x <= hi && arr[i]-x >= low)
        {
            printf("%lld\n", x);
            break;
        }
        if(arr[pos]+low>arr[pos+1]) continue;
        x = arr[pos]+low-m;
        if(arr[i-1] < x && arr[i]-x <= hi && arr[i]-x >= low)
        {
            printf("%lld\n", x);
            break;
        }
        x = m-arr[pos]+arr[i];
        if(x<2*low || x > 2*hi) continue;

        int nex = min(hi,arr[pos+1]-arr[pos]);
        if(nex+pre < x) continue;
        // printf("%lld\n", x);
        ll l1 = arr[i]-pre;
        ll r1 = arr[i]-low;
        ll l2 = arr[pos]+low-m;
        ll r2 = arr[pos]+nex-m;
        //printf("%lld %lld %lld %lld\n", l1, r1, l2, r2);
        if(l1<=r2 && l2 <=r1)
        {
            printf("%lld\n", max(l1,l2));
            break;
        }
    }
    return 0;
}


