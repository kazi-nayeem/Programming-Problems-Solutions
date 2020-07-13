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

#define MX 1000005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll flag[MX];

void sieve()
{
    for(int i = 2; i < MX; i++) flag[i] = i;
    for(ll i = 2; i < MX; i++)
    {
        if(flag[i] == i)
        {
            flag[i] = i-1;
            for(ll j = i+i; j < MX; j+=i)
                flag[j] -= flag[j]/i;
        }
    }
    for(int i = 3; i < MX; i++)
        flag[i] += flag[i-1];
}

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        printf("%lld\n", flag[n]);
    }
    return 0;
}




