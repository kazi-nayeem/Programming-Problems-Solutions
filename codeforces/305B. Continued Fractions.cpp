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

ll arr[1000];

int main()
{
    ll p, q;
    int n;
    scanf("%I64d %I64d", &p, &q);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", &arr[i]);
    ll gc = __gcd(p,q);
    p /= gc;
    q /= gc;
    for(int i = 1; i <= n; i++)
    {
        if(q == 0ll)
        {
            puts("NO");
            return 0;
        }
        ll m = p/q;
        if(m < arr[i])
        {
            puts("NO");
            return 0;
        }
        p -= arr[i]*q;
        swap(p,q);
    }
    if(p == 1 && q == 0)
        puts("YES");
    else
        puts("NO");
    return 0;
}


