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

char tem[MX];

string add(string a, string b)
{
    int len1 = a.size();
    int len2 = b.size();
    if(len1<len2)
    {
        swap(a,b);
        swap(len1,len2);
    }
    int pre = 0, pos = 0, res = -1;
    for(int i = 0; i < len2; i++)
    {
        pre += a[i]-'0';
        pre += b[i]-'0';
        tem[pos++] = (pre%10)+'0';
        pre/=10;
    }
    for(int i = len2; i < len1; i++)
    {
        pre += a[i]-'0';
        tem[pos++] = (pre%10)+'0';
        pre/=10;
    }
    if(pre>0)
        tem[pos++] = (pre%10)+'0';
    tem[pos] = 0;
    for(int i = 0; i < pos; i++)
    {
        if(tem[i] != '0') {
            res = i;
            break;
        }
    }
    return (string) (tem+res);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char str1[1000], str2[1000];
    while(scanf(" %[^,],%s", str1,str2) == 2)
    {
        cout<<add((string) str1, (string) str2)<<"\n";
    }
    return 0;
}


