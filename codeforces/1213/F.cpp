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

#define MX 200005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

int index1[MX];
int index2[MX];
int nxt[MX];
int test[MX];
char str[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &index1[i]);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &index2[i]);
        nxt[index2[i]] = i;
    }
    vector<int> seg;
    for(int i = 1; i <= n; i++)
    {
        test[i] = max(nxt[index1[i]], test[i-1]);
        if(test[i] == i)
        {
            seg.push_back(i);
        }
    }
    if(seg.size()<k)
    {
        puts("NO");
        return 0;
    }

    char ch = 'a';
    for(int i = 0; i < seg.size(); i++)
    {
        int last = 1;
        if(i>0)
        {
            last = seg[i-1]+1;
        }
        for(int j = last; j <= seg[i]; j++)
        {
            str[index1[j]-1] = ch;
        }
        if(ch<'z') ch++;
    }
    str[n] = 0;
    puts("YES");
    puts(str);
    return 0;
}

