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
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            int total = 0;
            for(int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                total += x;
            }
            ans ^= total;
        }
        printf("Case %d: ", te);
        if(ans)
            puts("Alice");
        else
            puts("Bob");
    }

    return 0;
}


