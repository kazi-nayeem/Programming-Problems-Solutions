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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

double dp[2][MX][MX];
char cas[2][MX][MX];

double func(int p, int w, int b)
{
    if(w == 0 && b == 0) return 0.0;
    double &res = dp[p][w][b];
    char & ch = cas[p][w][b];
    if(ch == 1) return res;
    ch = 1;
    if(p == 0)
    {
        res = (double) w*1.0/(w+b);
        if(b > 0)
            res += (double) func(1,w,b-1)*b*1.0/(w+b);
        return res;
    }
    res = 0.0;
    if(b>0 && w>0)
        res += (double) func(0,w-1,b-1)* b*1.0/(w+b)*w*1.0/(w+b-1);
    if(b>1)
        res += (double) func(0,w,b-2)*b*1.0/(w+b)*(b-1)*1.0/(w+b-1);
    return res;
}

int main()
{
    int w, b;
    scanf("%d %d", &w, &b);
    printf("%.12lf\n", func(0,w,b));
    return 0;
}


