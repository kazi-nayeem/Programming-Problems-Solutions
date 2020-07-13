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

#define MX 105
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

double dp[MX][2];
int cas[MX][2];
double pro[MX];
int n;

double func(int pos, int f)
{
    if(f > 1) return 0;
    if(pos == n+1) return 1.0;
    double & res = dp[pos][f];
    if(cas[pos][f] == 1) return res;
    cas[pos][f] = 1;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lf", &pro[i]);
    printf("%lf\n", func(1,0));
    return 0;
}


