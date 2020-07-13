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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int prv[MX];
int nxt[MX];
int arr[MX];
ll sum[MX];
int que[MX];
ll res[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &que[i]);
    ll mx = 0;
    for(int i = n; i >= 1; i--)
    {
        res[i] = mx;
        int pos = que[i];
        nxt[pos] = pos;

        if(prv[pos-1] == 0)
        {
            sum[pos] = arr[pos];
            prv[pos] = pos;
        }
        else
        {
            prv[pos] = prv[pos-1];
            nxt[prv[pos]] = pos;
            sum[prv[pos]] += arr[pos];
            sum[pos] = sum[prv[pos]];
        }
        mx = max(mx,sum[pos]);
        if(nxt[pos+1] != 0)
        {
            nxt[pos] = nxt[pos+1];
            nxt[prv[pos]] = nxt[pos];
            prv[nxt[pos]] = prv[pos];
            sum[nxt[pos]] += sum[prv[nxt[pos]]];
            sum[prv[nxt[pos]]] = sum[nxt[pos]];
            mx = max(mx,sum[nxt[pos]]);
        }
        /*puts(".......");
        for(int j = 1; j <= n; j++)
            printf("%d pos %d prv %d nxt %d sum %lld\n",j, pos, prv[j], nxt[j], sum[j]);
        puts(".......");
        getchar();*/
    }
    for(int i = 1; i <= n; i++)
        printf("%lld\n", res[i]);
    return 0;
}


