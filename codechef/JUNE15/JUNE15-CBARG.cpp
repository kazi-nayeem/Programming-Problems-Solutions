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
    int te, n;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &n);
        ll res = 0;
        int pre = 0, x;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(x>pre) res += x-pre;
            pre = x;
        }
        printf("%lld\n", res);
    }
    return 0;
}


