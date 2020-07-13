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

int func(int a, int b, int a1, int b1, int a2, int b2)
{
    if(a1>a) return 0;
    if(b1>b) return 0;
    int aa2 = a-a1;
    int bb2 = b-b1;
    if(aa2>=a2 && b>=b2) return a1*b1+a2*b2;
    if(a>=a2 && bb2>=b2) return a1*b1+a2*b2;
    return 0;
}

int arr[MX];
int arr2[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i], &arr2[i]);
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            ans = max(ans,func(a,b,arr[i],arr2[i],arr[j],arr2[j]));
            ans = max(ans,func(a,b,arr2[i],arr[i],arr[j],arr2[j]));
            ans = max(ans,func(a,b,arr[i],arr2[i],arr2[j],arr[j]));
            ans = max(ans,func(a,b,arr2[i],arr[i],arr2[j],arr[j]));
        }
    printf("%d\n", ans);
    return 0;
}

