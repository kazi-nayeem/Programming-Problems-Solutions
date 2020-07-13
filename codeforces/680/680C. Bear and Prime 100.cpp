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

int flag[1000];
int prime[1000];

void sieve()
{
    prime[0] = 2;
    int pos = 1;
    for(int i = 3; i <= 100; i+=2)
    {
        if(flag[i]) continue;
        prime[pos++] = i;
        for(int j = i*i; j <= 100; j+=i)
            flag[j] = 1;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    int cou = 0;
    for(int i = 0; i < 17; i++)
    {
        printf("%d\n", prime[i]);
        fflush(stdout);
        char str[100];
        scanf("%s", str);
        if(str[0] == 'y')
        {
            cou++;
            if(prime[i] <= 10)
            {
                prime[i] *= prime[i];
                i--;
            }
        }
        if(cou > 1) break;
    }
    if(cou>1)
        puts("composite");
    else
        puts("prime");
    return 0;
}


