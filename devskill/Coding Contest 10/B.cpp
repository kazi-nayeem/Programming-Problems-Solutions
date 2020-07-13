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

struct data
{
    int len;
    string a;
    data()
    {
        len = 0;
        a = "";
    }
    data(int n, string s)
    {
        len = n;
        a = s;
    }
    bool operator < (const data & p) const
    {
        if(len != p.len) return len < p.len;
        return a>=p.a;
    }
};

data dp[55][55][55];
int cs_dp[55][55][55];
char str1[55];
char str2[55];
char str3[55];
int te, ti;
int len1, len2, len3;

data func(int pos1, int pos2, int pos3)
{
    //printf("%d %d %d %d %d %d\n", pos1,pos2,pos3, len1, len2, len3);
    if(pos1>=len1 || pos2 >= len2 || pos3 >= len3) return data(0,"");
    //puts("ok");
    data & res = dp[pos1][pos2][pos3];
    if(cs_dp[pos1][pos2][pos3] == te) return res;
    cs_dp[pos1][pos2][pos3] = te;
    res = data(0,"");

    if(str1[pos1] == str2[pos2] && str2[pos2] == str3[pos3])
    {

        res = func(pos1+1,pos2+1,pos3+1);
        res.len++;
        res.a = str1[pos1]+res.a;
    }
    res = max(res,func(pos1+1,pos2,pos3));
    res = max(res,func(pos1+1,pos2+1,pos3));
    res = max(res,func(pos1+1,pos2,pos3+1));
    res = max(res,func(pos1,pos2+1,pos3));
    res = max(res,func(pos1,pos2+1,pos3+1));
    res = max(res,func(pos1,pos2,pos3+1));
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%s %s %s", str1,str2,str3);
        len1 = strlen(str1);
        len2 = strlen(str2);
        len3 = strlen(str2);
        data tem = func(0,0,0);
        if(tem.len == 0) tem.a = "T.A.T";
        printf("Case %d: %d %s\n", te, tem.len, tem.a.c_str());
    }
    return 0;
}

