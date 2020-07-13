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

char str[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int oo, oi, io, ii;
    scanf("%d %d %d %d", &oo, &oi, &io, &ii);
    int x = (1+ceil(sqrt(1+8*oo)))/2;
    if((x-1)*x != 2*oo)
    {
        puts("Impossible");
        return 0;
    }
    oo = x-1;
    x = (1+ceil(sqrt(1+8*ii)))/2;
    if((x-1)*x != 2*ii)
    {
        puts("Impossible");
        return 0;
    }
    ii = x-1;
    if(oo+ii+io+oi == 0)
    {
        puts("0");
        return 0;
    }
    if(oo+io+oi == 0)
    {
        for(int i = 0; i <= ii; i++)
            printf("1");
        puts("");
        return 0;
    }
    if(ii+io+oi == 0)
    {
        for(int i = 0; i <= oo; i++)
            printf("0");
        puts("");
        return 0;
    }
    if((oo+1)*(ii+1) != oi+io)
    {
        puts("Impossible");
        return 0;
    }
    for(int i = 0; i <= oo; i++)
        str[i] = '0';
    for(int i = 0; i <= ii; i++)
        str[i+oo+1] = '1';
    int moi = (oo+1)*(ii+1)-oi;
    for(int i = oo+1; i < oo+ii+2; i++)
    {
        //puts(str);
        if(moi <= 0) break;
        if(moi>=oo+1)
        {
            str[i] = '0';
            str[i-oo-1] = '1';
            moi -= oo+1;
        }
        else
        {
            str[i] = '0';
            str[i-moi] = '1';
            moi = 0;
        }
    }
    puts(str);
    return 0;
}


