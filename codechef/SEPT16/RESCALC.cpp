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

int cnt[6];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, n, p, x;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &n);
        int mx = 0, mxt = 0, res;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &p);
            memset(cnt,0,sizeof cnt);
            for(int j = 0; j < p; j++)
            {
                scanf("%d", &x);
                cnt[x-1]++;
            }
            sort(cnt,cnt+6);
            int point = p+cnt[0]*4+(cnt[1]-cnt[0])*2+(cnt[2]-cnt[1]);
            if(point>mx)
            {
                mx = point;
                mxt = 1;
                res = i;
            }
            else if(point == mx)
                mxt++;
        }
        if(mxt>1)
            puts("tie");
        else if(res == 1)
            puts("chef");
        else
            printf("%d\n", res);
    }
    return 0;
}


