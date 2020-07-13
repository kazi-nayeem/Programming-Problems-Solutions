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

#define MX 200005
#define inf 100000000

const ll mod = 1000000007ll;

map<int,int> mp;
int tree[4*MX];

void init(int n, int b, int e)
{
    if(b == e)
    {
        tree[n] = mod;
        return;
    }
    int m = (b+e)/2;
    int l = n<<1;
    int r = l+1;
    init(l,b,m);
    init(r,m+1,e);
    tree[n] = min(tree[l],tree[r]);
}

void update(int n, int b, int e, int p, int v)
{
    if(b>p || e < p) return;
    if(b == e && p == b)
    {
        tree[n] = min(v,tree[n]);
        return;
    }
    int m = (b+e)/2;
    int l = n<<1;
    int r = l+1;
    update(l,b,m,p,v);
    update(r,m+1,e,p,v);
    tree[n] = min(tree[l],tree[r]);
}

int query(int n, int b, int e, int i, int j)
{
    if(b>j || e < i) return mod;
    if(i <= b && e <= j)
    {
        return tree[n];
    }
    int m = (b+e)/2;
    int l = n<<1;
    int r = l+1;
    return min(query(l,b,m,i,j),query(r,m+1,e,i,j));
}

bool cmp(const pii & a, const pii &b)
{
    return a.second>b.second;
}

int func(int arr1[MX], int arr2[MX], int a, int b, int m)
{
    mp.clear();
    vector<pii> vc;
    for(int i = 0; i < m; i++)
    {
        if(min(arr1[i],arr2[i]) > b) continue;
        if(max(arr1[i],arr2[i]) < a) continue;
        vc.push_back(make_pair(max(a,min(arr1[i],arr2[i])), min(b,max(arr1[i],arr2[i]))));
    }
    mp[a] = 0;
    mp[b+1] = 0;
    for(int i = 0; i < vc.size(); i++)
    {
        mp[vc[i].first] = 0;
        mp[vc[i].second+1] = 0;
    }
    int cnt = 0;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        it->second = ++cnt;
    }
    init(1,1,cnt);
    update(1,1,cnt,mp[b+1],0);
    sort(vc.begin(),vc.end());
    for(int i = vc.size()-1; i >= 0; i--)
    {
        int tem = query(1,1,cnt,mp[vc[i].first],mp[vc[i].second+1]);
        update(1,1,cnt,mp[vc[i].first],tem+1);
    }
    return query(1,1,cnt,mp[a],mp[a]);
}

int xx1[MX];
int xx2[MX];
int yy1[MX];
int yy2[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, m, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d %d", &n, &k, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d %d", &xx1[i], &yy1[i], &xx2[i], &yy2[i]);
        }
        int ans = func(xx1,xx2,(n-k)/2+1,(n-k)/2+k,m);
        ans += func(yy1,yy2,(n-k)/2+1,(n-k)/2+k,m);
        if(ans>n) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}


