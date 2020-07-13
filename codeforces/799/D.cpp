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
int flag[MX];
int ans;

void func(int pos, ll a, ll b, ll h, ll w, int tk)
{
    if(( a<= h && b <= w) || ( a<= w && b <= h))
    {
        ans = min(ans,tk);
        return;
    }
    if(pos == -1) return;
    if((a>h || b > h) && (arr[pos] != arr[pos+1] || (flag[pos+1] == 1)))
    {
        flag[pos] = 1;
        func(pos-1,a,b,h*arr[pos],w,tk+1);
        flag[pos] = 0;
    }
    if(a>w || b > w)
        func(pos-1,a,b,h,w*arr[pos],tk+1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a, b, h, w;
    int n;
    scanf("%lld %lld %lld %lld %d", &a, &b, &h, &w, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr,arr+n);
    ans = inf;
    func(n-1,a,b,h,w,0);
    if(ans == inf)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}

