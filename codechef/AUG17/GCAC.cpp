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

#define MX 1005
#define inf 100000000

const ll mod = 1000000007ll;

ll minsalary[MX];
ll offer[MX];
int mxCan[MX];
int now[MX];
char str[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n, m;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &minsalary[i]);
        for(int i = 1; i <= m; i++)
        {
            scanf("%lld %d", &offer[i], &mxCan[i]);
            now[i] = 0;
        }
        offer[0] = 0;
        int hire = 0, comp = 0;
        ll total = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf(" %s", str);
            int pos = 0;
            for(int j = 1; j <= m; j++)
            {
                if(str[j-1] == '0') continue;
                if(mxCan[j] == now[j]) continue;
                if(offer[j]>offer[pos])
                {
                    pos = j;
                }
            }
            if(offer[pos]>=minsalary[i])
            {
                hire++;
                total += offer[pos];
                now[pos]++;
            }
        }
        for(int i = 1; i <= m; i++)
            comp += now[i]>0;
        printf("%d %lld %d\n", hire, total, m-comp);
    }
    return 0;
}

