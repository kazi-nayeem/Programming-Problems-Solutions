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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bool flag = true;
    for(int i = 1; i < n; i++)
    {
        int low = min(arr[i],arr[i-1]);
        int hi = max(arr[i],arr[i-1]);
        for(int j = 1; j < n; j++)
        {
            if(i == j) continue;
            int low1 = min(arr[j],arr[j-1]);
            int h1 = max(arr[j],arr[j-1]);
            if(h1<=hi && low1>= low) continue;
            if(h1>=hi && low1<= low) continue;
            if(h1<=low || low1>=hi) continue;
            //printf("%d %d\n", low, hi);
            //printf("%d %d\n", low1, h1);
            flag = false;
        }
        if(!flag) break;
    }
    if(!flag) puts("yes");
    else puts("no");
    return 0;
}


