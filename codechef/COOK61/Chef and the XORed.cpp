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

int main()
{
   // for(int i = 0; i < 1000; i++)
        //printf("%d\n", i^(i+1));
    int te;
    scanf("%d", &te);
    while(te--)
    {
        ll n;
        int pos = -1;
        scanf("%lld", &n);
        if(n == 1)
        {
            puts("2");
            continue;
        }
        for(int i = 0; i < 40; i++)
        {
            ll mx = (ll) 1ll<<i;
            mx--;
            if(mx == n)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1 || n <= 1)
            puts("-1");
        else
        {
            printf("%lld\n", (1ll<<(pos-1))-1);
        }
    }
    return 0;
}

