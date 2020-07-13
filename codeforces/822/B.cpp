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

char str1[MX];
char str2[MX];
int len1, len2;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d %s %s", &len1, &len2, str1, str2);
    int cost = len1+10;
    int pos = 0;
    for(int i = 0; i+len1 <= len2; i++)
    {
        int ans = 0;
        for(int j = 0; j < len1; j++)
        {
            if(str1[j] != str2[i+j]) ans++;
        }
        if(cost>ans) pos = i, cost = ans;
    }
    printf("%d\n", cost);
    for(int i = 0; i < len1; i++)
        if(str1[i] != str2[pos+i]) printf("%d ", i+1);
    puts("");
    return 0;
}

