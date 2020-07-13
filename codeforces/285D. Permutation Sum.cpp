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

map<pair<int,int>, ll> mp;
int n;
const ll mod = 1000000007ll;

ll func(int i, int mask2, int mask3)
{
    if(i == n) return 1;

    if(mp.find(make_pair(mask2,mask3)) != mp.end()) return mp[make_pair(mask2,mask3)];

    ll &res = mp[make_pair(mask2,mask3)];
    res = 0;
    for(int j = 0; j < n; j++)
    {
        if(((mask2>>j)&1) == 1) continue;
        if(((mask3>>((i+j)%n))&1) == 1) continue;
        res += func(i+1, mask2| (1<<j), mask3| (1<<((i+j)%n)));
        res %= mod;
    }
    return res;
}

ll res[100] = {0 , 1 , 0 , 18 , 0 , 1800 , 0 , 670320 , 0 , 734832000 , 0 , 890786230 , 0 , 695720788 , 0 , 150347555};

int main()
{
    /*ll fact = 1;
    for(int i = 1; i <= 16; i+=2)
    {
        mp.clear();
        n = i;
        fact = (fact*i)%mod;
        if(i > 1) fact = (fact*(i-1))%mod;
        printf(", 0 , %lld ", (func(0,0,0)*fact)%mod);
        //getchar();
    }*/
    scanf("%d", &n);
    printf("%I64d\n", res[n]);

    return 0;
}


