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
    int a, n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &a);
        if(360%(180-a) == 0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}


