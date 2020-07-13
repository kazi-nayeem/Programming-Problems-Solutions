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
    ll t1, t2, pre1,pre2;
    int te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%lld %lld %lld %lld", &t1, &t2, &pre1, &pre2);
        double res = 0.0;
        ll total = t1*t2;
        ll f1 = min(t1,t2);
        ll f2 = min(pre1,pre2);
        ll f3 = max(pre1,pre2);

        ll r1 = min(f1,f2);
        double tem = (double) (r1+1.0)*r1/total;
        tem /= 2.0;
        res += tem;

        ll r2 = min(f1,f3);
        tem = (double) (r2-r1);
        tem *= r1+1.0;
        tem /= total;
        res += tem;

        tem = (double) (f1-r2)*(r2+1.0)/total;
        res += tem;
        printf("%lf\n", res);
    }
    return 0;
}
