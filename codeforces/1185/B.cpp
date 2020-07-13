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

#define MX 1000005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

char str1[MX];
char str2[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf(" %s %s", str1, str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int pos1 = 0;
        int pos2 = 0;
        while(pos1<=len1 && pos2<len2)
        {
            //printf("%d %d\n" pos1, pos2);
            if(str1[pos1] == str2[pos2])
            {
                pos1++;
                pos2++;
                continue;
            }
            if(pos1 == 0)
            {
                break;
            }
            if(str1[pos1-1] == str2[pos2])
            {
                pos2++;
                continue;
            }
            break;
        }
        if(pos1 == len1 && pos2 == len2)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}

