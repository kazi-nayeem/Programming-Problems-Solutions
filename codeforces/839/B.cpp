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
    int n, k, x;
    scanf("%d %d", &n, &k);
    int two = 0, four = 0, one = 0;
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &x);
        four += x/4;
        x %= 4;
        if(x == 1) one++;
        else if(x == 2) two++;
        else if(x == 3) four++;
    }
    //printf("%d %d %d\n", one, two, four);
    int mi = min(n,four);
    four -= mi;
    int way4 = n-mi;
    two += four*2;
    //printf("%d %d %d\n", one, two, four);
    mi = min(min(one,two),way4);
    one -= mi;
    two -= mi;
    way4 -= mi;
    mi = min(two,2*n);
    two -= mi;
    int way2 = 2*n-mi;
    //printf("%d %d %d\n", one, two, four);
    //printf("%d %d %d %d %d\n", one, two, four, way2, way4);
    if(one+two<=way4+way2 || (two == 0 && one<=way4*2+way2) || (way2 == 0 && one+2*two<=3*way4))
        puts("YES");
    else
        puts("NO");
    return 0;
}


