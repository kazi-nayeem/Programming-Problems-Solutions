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

ll arr[MX];

int main()
{
    ll pos = 0;
    for(ll i = 1; i < MX; i++)
    {
        arr[i] = arr[i-1]+i*i;
        pos = i;
        if(arr[i] > 10000000050000000ll)
            break;
    }
    ll n;
    int te, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%lld", &n);
        printf("%d\n", upper_bound(arr,arr+pos,n)-arr-1);
    }
    return 0;
}


