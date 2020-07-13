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



struct node
{
    int count;
    node *left, *right;
    node(int count, node *left, node *right):
        count(count), left(left), right(right) {}
    node* insert(int l, int r, int w);
};

node *null = new node(0,NULL,NULL);

node* node::insert(int l, int r, int w)
{
    if(w < l || r < w) return this;
    if(l == r)
    {
        return new node(this->count+1,null,null);
    }
    int m = (l+r)>>1;
    return new node(this->count+1,this->left->insert(l,m,w), this->right->insert(m+1,r,w));
}

int query(node *a, node *b, int l, int r, int k)
{
    if(l == r)
    {
        return l;
    }
    int m = (l+r)>>1;
    int count = a->left->count - b->left->count;
    if(count>=k)
        return query(a->left,b->left,l,m,k);
    return query(a->right,b->right,m+1,r,k-count);
}

int a[MX], RM[MX];
node *root[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    map<int,int> mp;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mp[a[i]];
    }
    int maxi = 0;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        it->second = maxi;
        RM[maxi] = it->first;
        maxi++;
    }
    null->left = null->right = null;
    root[0] = null;
    for(int i = 1; i <= n; i++)
    {
        root[i] = root[i-1]->insert(0,maxi,mp[a[i]]);
    }
    while(m--)
    {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        int ans = query(root[v],root[u-1],0,maxi,k);
        printf("%d\n", RM[ans]);
    }
    return 0;
}


