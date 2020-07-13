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
    double ans = 0.0;
    int n, m;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++)
    {
        ans += (double) i*(pow((double) i/m,n)-pow((double) (i-1)/m,n));
    }
    printf("%.12lf\n", ans);
    return 0;
}


