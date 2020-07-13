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

string getres(int a, int b)
{
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    string s;
    cin>>s;
    return s;
}

int func2(int a, int b)
{
    if(a>b) return -1;
    if(a == b) return a;
    int m = (a+b)/2;
    string tem1 = getres(m,m+1);
    if(tem1 == "NIE")
    {
        return func2(m+1,b);
    }
    return func2(a,m);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    int res1 = func2(1,n);
    //printf("%d\n", res1);
    if(res1 != 1)
    {
        int res2 = func2(1,res1-1);
        if(getres(res2,res1) == "TAK")
        {
            printf("2 %d %d\n", res1, res2);
            fflush(stdout);
            return 0;
        }
    }
    int res3 = func2(res1+1,n);
    printf("2 %d %d\n", res1,res3);
    fflush(stdout);
    return 0;
}

