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

int arr[2*MX];
int cnt[2*MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i+n] = arr[i];
    }
    for(int i = 1; i < 2*n; i++)
    {
        if(arr[i]>i) continue;
        cnt[i-arr[i]]++;
        if(i>n)
            cnt[i-n-1]--;
    }
    int mx = -1, pos = -1;
    int sum = 0;
    for(int i = 2*n-1; i>= 1; i--)
    {
        sum += cnt[i];
        if(mx>sum) continue;
        mx = sum;
        pos = i;
    }
    printf("%d\n", pos);
    return 0;
}


