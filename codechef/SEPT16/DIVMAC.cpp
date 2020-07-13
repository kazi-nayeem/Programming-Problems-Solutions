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

#define MX 1000005
#define step 22
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

vector<int> fact;
int flag[MX];

struct data
{
    int arr[step];
    int lazy;
};

data tree[MX];
int arr[MX];

void func()
{
    for(ll i = 2; i < MX; i++)
    {
        if(flag[i]) continue;
        //printf("%lld\n", i);
        fact.push_back(i);
        for(ll j = i; j < MX; j += i)
            flag[j] = 1;
    }
    /*for(int i = 0; i < 100; i++)
    {
        printf("%d ->", i);
        for(int j = 0; j < fact[i].size(); j++)
            printf(" %d", fact[i][j]);
        puts("");
    }*/
    /*for(int i = 0; i < 100; i++)
        {
            printf("%d %d\n", i, fact[i]);
        }*/
    //printf("%d\n", fact.size());
}

void build_tree(int node, int beg, int en)
{
    if(beg == en)
    {
        int n = arr[beg];
        int pos = 0;
        for(int i = 0; (((ll) fact[i]*fact[i]) <= n) && i < fact.size();)
        {
            if((n%fact[i]) == 0)
            {
                tree[node].arr[pos++] = fact[i];
                n /= fact[i];
            }
            else i++;
        }
        if(n>1)
            tree[node].arr[pos++] = n;
        while(pos<step)
        {
            tree[node].arr[pos++] = 1;
        }
        tree[node].lazy = 0;
        return;
    }
    int mid = (beg+en)/2;
    int lef =node<<1;
    int righ = lef+1;
    build_tree(lef,beg,mid);
    build_tree(righ,mid+1,en);
    for(int i = 0; i < step; i++)
        tree[node].arr[i] = max(tree[lef].arr[i],tree[righ].arr[i]);
    tree[node].lazy = 0;
}

void update_tree(int node, int beg, int en, int i, int j, int pos)
{
    if(pos == 0) return;
    if(i > en || j < beg) return;
    if(tree[node].arr[0] == 1) return;
    if(i <= beg && en <= j)
    {
        tree[node].lazy += pos;
        for(int i = 0; i + pos < step; i++)
        {
            if(tree[node].arr[i] == 1) break;
            tree[node].arr[i] = tree[node].arr[i+pos];
        }
        for(int i = max(step-pos,0); i < step; i++)
        {
            if(tree[node].arr[i] == 1) break;
            tree[node].arr[i] = 1;
        }
        return;
    }
    int mid = (beg+en)/2;
    int lef =node<<1;
    int righ = lef+1;
    if(tree[node].lazy != 0)
    {
        update_tree(lef,beg,mid,beg,en,tree[node].lazy);
        update_tree(righ,mid+1,en,beg,en,tree[node].lazy);
    }
    update_tree(lef,beg,mid,i,j,pos);
    update_tree(righ,mid+1,en,i,j,pos);
    for(int i = 0; i < step; i++)
        tree[node].arr[i] = max(tree[lef].arr[i],tree[righ].arr[i]);
    tree[node].lazy = 0;
}

int query_tree(int node, int beg, int en, int i, int j)
{
    if(i > en || j < beg) return 1;
    if(i <= beg && en <= j)
    {
        return tree[node].arr[0];
    }
    int mid = (beg+en)/2;
    int lef =node<<1;
    int righ = lef+1;
    if(tree[node].lazy != 0)
    {
        update_tree(lef,beg,mid,beg,en,tree[node].lazy);
        update_tree(righ,mid+1,en,beg,en,tree[node].lazy);
        for(int i = 0; i < step; i++)
            tree[node].arr[i] = max(tree[lef].arr[i],tree[righ].arr[i]);
        tree[node].lazy = 0;
    }
    int res = max(1,query_tree(lef,beg,mid,i,j));
    res = max(res,query_tree(righ,mid+1,en,i,j));
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    func();
    int te, n, q, a, x, y;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        build_tree(1,1,n);
        bool flag = false;
        for(int i = 0; i < q; i++)
        {
            scanf("%d %d %d", &a, &x, &y);
            if(a == 0)
                update_tree(1,1,n,x,y,1);
            else
            {
                if(flag) printf(" ");
                flag = true;
                printf("%d", query_tree(1,1,n,x,y));
            }
        }
        puts("");
    }
    return 0;
}


