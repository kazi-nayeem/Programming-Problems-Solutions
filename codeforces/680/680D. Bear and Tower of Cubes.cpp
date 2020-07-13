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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll qube(ll i)
{
    return i*i*i;
}

int number[MX];
ll res = 0;
int num = 0;

void func(int pos, int to, ll baki)
{
    if(baki < 0) return;
    if(to > num)
    {
        num = to;
        res = baki;
    }
    else if(to == num && baki < res)
    {
        num = to;
        res = baki;
    }
    if(pos <= 0) return;
    //printf("%d %d %lld\n", pos, to, baki);
    for(int i = 0; i <= number[pos]; i++)
    {
        func(pos-1,to+i, baki-(i*qube(pos)));
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    scanf("%lld", &n);
    int pos;
    for(ll i = 1;  qube(i)<= n; i++)
    {
        pos = i;
        number[i] = qube(i+1)/qube(i);
        printf("%lld %lld %lld \n", i, qube(i+1)/qube(i), qube(i));
    }
    number[1]--;
    func(pos,0,n);
    printf("%d %lld\n", num, n-res);
    return 0;
}


