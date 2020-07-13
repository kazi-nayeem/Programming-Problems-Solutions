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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, x1, x2, y1, y2;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld", &n, &x1, &y1, &x2, &y2);
        ll cov1;
        if(y1 == y2)
        {
            cov1 = n;
        }
        else
        {
            if(x1 == x2)
            {
                cov1 = abs(y1-y2)/2;
                cov1 *= 2;
                if(y1<y2)
                    cov1 += 2*y1;
                else
                    cov1 += (n-y1+1)*2;
            }
            else
            {
                if(y1<y2)
                {
                    if(y1>n-y2)
                        cov1 = n+10;
                    else if(n-y2>y1)
                        cov1 = 0;
                    else
                        cov1 = n;
                }
                else
                {
                    if(y2-1<n-y1+1)
                        cov1 = n+10;
                    else if(y2-1 > n-y1+1)
                        cov1 = 0;
                    else
                        cov1 = n;
                }
            }
        }
        //printf("%lld\n", cov1);
        if(cov1 == n)
            puts("Draw");
        else if(cov1>n)
            puts("Miron");
        else
            puts("Slava");
    }
    return 0;
}

