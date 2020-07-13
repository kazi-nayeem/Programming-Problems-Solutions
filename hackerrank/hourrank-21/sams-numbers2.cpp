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


#define MX 100005
#define inf 100000000

const ll mod = 1000000009ll;

struct mat
{
    ll arr[150][150];
};

int row;

mat multi(mat a, mat b)
{
    mat res;
    memset(res.arr,0,sizeof res.arr);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < row; j++)
        {
            for(int k = 0; k < row; k++)
                res.arr[i][j] += (a.arr[i][k]*b.arr[k][j])%mod;
            res.arr[i][j] %= mod;
        }
    return res;
}

mat unit(int r)
{
    mat res;
    memset(res.arr,0,sizeof res.arr);
    for(int i = 0; i < r; i++)
        res.arr[i][i] = 1;
    return res;
}

mat BigMod(mat B,ll P)
{
    mat R = unit(row);    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=multi(R,B);
        }
        P/=2;
        B=multi(B,B);
    }
    return R;
}

int m, d;

int getID(int i, int j)
{
    return (m+1)*(i-1)+j;
}

mat getMatrix()
{
    mat res;
    memset(res.arr,0,sizeof res.arr);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(j<m)
                res.arr[getID(i,j)][getID(i,j+1)];
            if(abs(i-j)<=d)
                res.arr[getID(i,j)][getID(j,1)];
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll s;

    cin>>s>>m>>d;
    ll ans = 0;
    for(int i = 1; i <= min((ll) m,s); i++)
    {
        if(i == s)
        {
            ans++;
            ans %= mod;
            continue;
        }
        mat res = BigMod(getMatrix(),s-i-1);
    }
    cout<<ans;
    return 0;
}


