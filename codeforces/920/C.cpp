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
#include<complex>
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

#define MX 1000005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

int arr[MX];
char str[MX];
int pre[MX];
int nxt[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i]--;
    }
    scanf("%s", str);
    int now = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(str[i] == '0')
        {
            now = i+1;
        }
        pre[i+1] = now;
    }
    nxt[n-1] = n-1;
    now = n-1;
    for(int i = n-2; i >= 0; i--)
    {
        if(str[i] == '0')
            now = i;
        nxt[i] = now;
    }
//    for(int i = 0; i < n; i++)
//        printf("%d %d\n", pre[i], nxt[i]);
    bool ans = true;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]>=pre[i] && arr[i] <= nxt[i])
            continue;
        ans = false;
        break;
    }
    if(ans)
        puts("YES");
    else
        puts("NO");
    return 0;
}


