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

ll fact[20];
ll arr[20];
int coun[200];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fact[0] = 1;
    for(int i = 1; i <= 18; i++)
        fact[i] = fact[i-1]*i;
    int n;
    scanf("%d", &n);
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i] < arr[i-1])
        {
            flag = false;
        }
        coun[arr[i]]++;
    }
    if(flag)
    {
        printf("%.6lf\n", 0.00);
        return 0;
    }
    ll p = fact[n];
    for(int i = 1; i <= 100; i++)
        p /= fact[coun[i]];
    printf("%.6lf\n", p*1.0);
    return 0;
}


