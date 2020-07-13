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

ll arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n, d;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &d);
        ll total = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            total += arr[i];
        }
        if(total%n != 0)
        {
            puts("-1");
            continue;
        }
        ll make = total/n;
        int pos1 = 1, pos2 = 1;
        ll ans = 0;
        for(int i = 1; i+d <= n; )
        {
            //while(pos1<n && pos1<i+d && arr[pos1]>=make) pos1++;
            //while(pos2<n && pos2<i+d &&arr[pos2]<=make) pos2++;
//            printf("%d %d %d\n", i, pos1, pos2);
//            for(int j = 1; j <= n; j++)
//                printf("%lld ", arr[j]);
//            puts("");
//            getchar();
            int pos1 = i+d;
            int pos2 = i+d;
            if(arr[i] == make)
            {
                i++;
                continue;
            }
            if(arr[i]<make)
            {
                ll tk = make-arr[i];
                if(arr[pos2]>make)
                {
                    tk = min(tk,arr[pos2]-make);
                }
                ans += tk;
                arr[i] += tk;
                arr[pos2] -= tk;
            }
            else
            {
                ll tk = arr[i]-make;
                if(arr[pos1]<make)
                {
                    tk = min(tk,make-arr[pos1]);
                }
                ans += tk;
                arr[i] -= tk;
                arr[pos1] += tk;
            }
        }
        for(int i = 1; i <= n; i++)
            if(arr[i] != make) ans = -1;
        printf("%lld\n", ans);
    }
    return 0;
}


