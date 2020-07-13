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

int n, m, k;

pii add(pii a)
{
    if(a.first == 0 && a.second<n)
    {
        return make_pair(0,a.second+1);
    }
    if(a.first == n && a.second>0)
    {
        return make_pair(n,a.second-1);
    }
    if(a.second == 0 && a.first>0)
    {
        return make_pair(a.first-1,0);
    }
    if(a.second == n && a.first<n)
    {
        return make_pair(a.first+1,n);
    }
    return make_pair(0,0);
}

map<pii,int> mp;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x, y;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        mp[make_pair(x,y)]++;
    }
    int tk = mp[make_pair(0,0)];
    int cost = 0;
    pii now = make_pair(0,0);
    pii last = make_pair(0,0);
    int ans = 4*n+10;
    for(int i = 0; i <= 4*n; i++)
    {
        while(tk<k)
        {
            last = add(last);
            //printf(">>last %d %d >> %d\n", last.first,last.second, mp[last]);
            cost++;
            tk += mp[last];
        }
        //printf("last %d %d\n\n", last);
        ans = min(ans,cost);
        cost--;
        //printf("now %d %d\n", now);
        tk -= mp[now];
        now = add(now);
        //printf("now %d %d\n", now);
    }
    printf("%d\n", ans);
    return 0;
}

