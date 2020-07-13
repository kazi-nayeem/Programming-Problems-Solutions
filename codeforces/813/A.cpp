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

int flag[MX];
int arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, l, r = 0;
    int tot = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        tot += arr[i];
    }
    sort(arr,arr+n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &l, &r);
        for(int j = l; j <= r; j++)
            flag[j] = 1;
    }
    for(int i = r; i >= 0; i--)
    {
        if(flag[i] == 1) flag[i] = i;
        else flag[i] = flag[i+1];
    }
    if(tot > r)
    {
        puts("-1");
        return 0;
    }
    int pre = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        pre += arr[i];
        ans = max(flag[pre],ans);
    }
    printf("%d\n", ans);
    return 0;
}

