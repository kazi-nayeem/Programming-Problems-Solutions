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

ll mod = 1000000007;

ll bigmod(ll a, ll p)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2);
    res *= res;
    res %= mod;
    if(p % 2 == 1)
        res *= a;
    res %= mod;
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    ll res = bigmod(3,3*n)-bigmod(7,n);
    res += mod;
    res %= mod;
    cout<<res<< endl;
    return 0;
}


