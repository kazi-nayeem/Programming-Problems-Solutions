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
using namespace std;

#define ll long long

double p;

double dp[2005][2005];
char cas[2005][2005];

double func(int per, int tim)
{
    if(per == 0 || tim == 0) return 0.0;
    double & res = dp[per][tim];
    if(cas[per][tim] == 1) return res;
    cas[per][tim] = 1;
    res = p*(func(per-1,tim-1)+1);
    res += (1.0-p)*func(per,tim-1);
    return res;
}

int main()
{
    int n, t;
    scanf("%d %lf %d", &n, &p, &t);
    printf("%.10lf\n", (double)func(n,t));
    return 0;
}

