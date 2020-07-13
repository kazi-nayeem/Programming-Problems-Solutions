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

char str[MX];
int len;
int arr[100];
int flag[100];
int res;

bool check()
{
    int pos = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == arr[pos]+'0')
            pos++;
        if(pos == 10)
            return true;
    }
    return false;
}

void back_track(int pos)
{
    if(pos == 10)
    {
        if(check())
            res++;
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        if(flag[i])
            continue;
        arr[pos] = i;
        flag[i] = 1;
        back_track(pos+1);
        flag[i] = 0;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(str);
    len = strlen(str);
    back_track(0);
    printf("%d\n", res);
//    for(int i = 0; i < 9; i++)
//        arr[i] = i+1;
//    arr[9] = 0;
//    if(check()) puts("yes");
    return 0;
}

