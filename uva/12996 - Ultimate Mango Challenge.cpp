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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[MX];
int arr2[MX];

bool func(int n)
{
    for(int i = 0; i < n; i++)
        if(arr[i] > arr2[i]) return false;
    return true;
}

int main()
{
    int te, ti, n, l;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &l);
        int to = 0;
        for(int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
                to += arr[i];
            }
        for(int i = 0; i < n; i++)
            scanf("%d", &arr2[i]);
        printf("Case %d: ", te);
        if(to <= l && func(n))
            puts("Yes");
        else
            puts("No");

    }
    return 0;
}



