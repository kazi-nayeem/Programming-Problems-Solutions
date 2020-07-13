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

int flag[MX];
int nex[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &nex[i]);
    }
    bool f = true;
    ll res = 1;
    for(int i = 1; i <= n; i++)
    {
        if(flag[i]) continue;
        int j = i, cnt = 0;
        while(flag[j] == 0)
        {
            flag[j] = 1;
            j = nex[j];
            cnt++;
        }
        if(j != i)
        {
            f = false;
            break;
        }
        if(cnt%2 == 0) cnt/=2;
        res = res/__gcd(res,(ll) cnt)*cnt;
    }
    if(!f) res = -1;
    printf("%I64d\n", res);
    return 0;
}

