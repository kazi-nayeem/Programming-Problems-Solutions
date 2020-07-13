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

int arr[4];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < 4; i++)
        scanf("%d", &arr[i]);
    sort(arr,arr+4);
    for(int i = 2; i < 4; i++)
    {
        if(arr[i-2]+arr[i-1] > arr[i])
        {
            puts("TRIANGLE");
            return 0;
        }
    }
    for(int i = 2; i < 4; i++)
    {
        if(arr[i-2]+arr[i-1] == arr[i])
        {
            puts("SEGMENT");
            return 0;
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}


