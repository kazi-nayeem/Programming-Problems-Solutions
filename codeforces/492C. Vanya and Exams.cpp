#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 200005
#define MXP 4794
#define ll long long

struct data
{
    int a, b;
    bool operator < (const data & p) const
    {
        return b < p.b;
    }
};

data arr[100005];

int main()
{
    int n, r, avg;
    ll total = 0, cost = 0;
    scanf("%d%d%d", &n, &r, &avg);
    total = (ll) n*avg;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].a, &arr[i].b);
        total -= arr[i].a;
    }
    sort(arr,arr+n);
    for(int i = 0; i < n && total > 0; i++)
    {
        if(total >= r-arr[i].a)
        {
            total -= r-arr[i].a;
            cost += (ll) (r-arr[i].a)*arr[i].b;
        }
        else
        {
            cost += (ll) total * arr[i].b;
            total = 0;
        }
    }
    printf("%I64d\n", cost);
    return 0;
}
