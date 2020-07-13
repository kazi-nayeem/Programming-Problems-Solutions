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

int arr[MX];

int pos = 0;

int n, k;

int getpos(int a)
{
    while(arr[pos+1] <= a && pos<n) pos++;
    return pos;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf(" %d", &arr[i]);
    sort(arr+1,arr+n+1);
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        i = getpos(arr[i]+k);
        i = getpos(arr[i]+k);
        res++;
    }
    printf("%d\n", res);
    return 0;
}

