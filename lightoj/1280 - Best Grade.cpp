//#include <bits/stdc++.h>

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MX 20005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

const double est = 1e-6;

double mid;

struct data
{
    int t, g;
    bool operator < (const data &p) const
    {
        double x1 = (double) g-t*mid;
        double x2 = (double) p.g-p.t*mid;
        return x1<x2;
    }
};

data arr[MX];

double func(int d, int n)
{
    double total = 0.0, get = 0.0;
    for(int i = d; i < n; i++)
    {
        total += (double) arr[i].t;
        get += (double) arr[i].g;
    }
    return (double) get/total;
}

int main()
{
    int te, ti, n, d;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &d);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &arr[i].g, &arr[i].t);
        }
        double low = 0.0, hi = 1.0, avg = 0.0;
        while(fabs(low-hi) > est)
        {
            mid = (hi+low)/2.0;
            sort(arr,arr+n);
            double tem = func(d,n);
            if(tem < mid)
                hi = mid;
            else
            {
                low = mid;
                if(tem>avg)
                    avg = tem;
            }
        }
        printf("Case %d: %.9lf\n", te, (double) 100.0*avg);
    }
    return 0;
}


