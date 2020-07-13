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

#define MX 10000005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

int nxt[MX];
int prime[MX];
int flag[MX];
int avail[MX];

bool check(int n)
{
    while(n>1)
    {
        //printf("%d\n", n);
        if(avail[flag[n]])
            return false;
        n /= flag[n];
    }
    return true;
}

void block(int n)
{
    while(n>1)
    {
        avail[flag[n]] = 1;
        n /= flag[n];
    }
}

int find_nxt(int n)
{
    if(nxt[n] != n)
        return nxt[n] = find_nxt(nxt[n]);
    if(avail[n] == 1)
        return nxt[n] = find_nxt(n+1);
    if(!check(n))
        return nxt[n] = find_nxt(n+1);
    return n;
}

void sieve()
{
    int pos = 0;
    for(int i = 2; i < MX; i++)
    {
        nxt[i] = i;
        if(flag[i] == 0)
        {
            prime[pos++] = i;
            for(int j = i; j < MX; j+=i)
                flag[j] = i;
        }
    }
//    for(int i = 0; i < 100; i++)
//        printf("%d %d\n", i, prime[i], flag[i]);
    //printf("%d\n", pos);
}

int arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();

    int n, x, xn;
    scanf("%d", &n);
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        xn = x;
        if(!flag)
        {
            xn = 2;
        }
        while(!check(xn))
        {
            xn = find_nxt(xn);
        }
        if(xn>x)
            flag = false;
        arr[i] = xn;
        avail[xn] = 1;
        block(xn);
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    puts("");
    return 0;
}

