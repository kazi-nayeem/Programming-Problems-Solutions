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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

struct maTix
{
    ll arr[2][2];
};

maTix mat, unit;
ll mod;

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2,m);
    res = (res*res)%m;
    if(p%2 == 1) res = (res*a)%m;
    return res;
}

maTix multiply(maTix a, maTix b)
{
    maTix res;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            res.arr[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
                res.arr[i][j] %= mod;
            }
        }
    return res;
}

maTix matexp(ll p)
{
    if(p == 0) return unit;
    if(p == 1) return mat;
    if(p%2ll == 1ll)
        return multiply(mat,matexp(p-1));
    maTix res = matexp(p/2);
    return multiply(res,res);
}

int main()
{
    unit.arr[0][0] = unit.arr[1][1] = 1;
    unit.arr[0][1] = unit.arr[1][0] = 0;
    mat.arr[0][0] = mat.arr[0][1] = mat.arr[1][0] = 1;
    mat.arr[1][1] = 0;

    ll n, k, m;
    int l;
    cin>>n>>k>>l>>mod;
    m = mod;
    //printf("%d\n", pos);
    ll res = (1ll)%m;
    if((k>>l) == 0 || l == 64)
    {
        for(int i = l-1; i >= 0; i--)
        {
            maTix temm = matexp(n);
            ll tem2 = temm.arr[0][0]+temm.arr[0][1];
            tem2 %= m;
            //tem = (tem*n)%m;
            if(((k>>i)&1ll) == 1ll)
            {
                ll tem = bigmod(2,n,m);
                tem2 = (tem-tem2+m)%m;
            }
            res =(res*tem2)%m;
        }
    }
    else res = 0ll;
    cout<<res<<endl;
    return 0;
}
