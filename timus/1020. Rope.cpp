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

const double pi = acos(-1);

int n;
double x[MX];
double y[MX];
double r;

double sqr(double a)
{
    return a*a;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

int main()
{
    while(scanf("%d %lf", &n, &r) == 2)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &x[i], &y[i]);
        }
        double ans = 0;
        for(int i = 1; i < n; i++)
            ans += dist(x[i-1], y[i-1], x[i], y[i]);

        ans += dist(x[n-1], y[n-1], x[0], y[0]);
        ans += 2.0 * r * pi;
        printf("%.2lf\n", ans);
    }
    return 0;
}
