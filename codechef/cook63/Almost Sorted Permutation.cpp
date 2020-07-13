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

#define MX 1000005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[MX];

int main()
{
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for(int i = 2; i <= n; i++)
        {
            if(arr[i] >= arr[i-1]) continue;
            swap(arr[i],arr[i-1]);
            i++;
        }
        bool flag = true;
        for(int i = 2; i <= n; i++)
        {
            if(arr[i-1] > arr[i]) flag = false;
        }
        if(flag) puts("YES");
        else
        puts("NO");
    }
    return 0;
}


