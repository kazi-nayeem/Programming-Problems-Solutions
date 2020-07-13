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

int arr[MX];

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
        }
        bool flag = true;
        for(int i = 0; i < m; i++)
        {
            int ans = 0;
            for(int j = 0; j < m; j++)
            {
                if(i == j)
                {
                    ans ^= arr[i]-1;
                }
                else
                    ans ^= arr[i]-1;
            }
            if(ans == 0)
            {
                flag = false;
                break;
            }
        }
        printf("Case %d: ", te);
        //printf("%d", ans);
        if(flag)
            puts("Alice");
        else
            puts("Bob");
    }

    return 0;
}


