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

#define MX 100005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

char str[100];

int input(int id)
{
    printf("%d\n", id);
    fflush(stdout);
    scanf("%s", str);
    if(str[0] == 'V')
        exit(0);
    if(str[0] == 'M')
        return 1;
    if(str[0] == 'F')
        return 2;
}

void func(int n)
{
    int st = input(0);
    int l = 0, r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        int typ = input(mid);
        if(mid%2 == 0)
        {
            if(typ == st)
                l = mid+1;
            else
                r = mid-1;
        }
        else
        {
            if(typ != st)
                l = mid+1;
            else
                r = mid-1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    func(n);
    return 0;
}

