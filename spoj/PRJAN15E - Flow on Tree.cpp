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
#define MX 100005


struct data
{
    int u, v, cost;
    data() {}
    data(int a, int b, int c)
    {
        u = a;
        v = b;
        cost = c;
    }
    bool operator < (const data& p) const
    {
        return cost > p.cost;
    }
};

int par[MX], ran[MX];
vector<data> vc;
ll total;

int find_par(int n)
{
    if(par[n] == n) return n;
    return par[n] = find_par(par[n]);
}

void mst(int n)
{
    sort(vc.begin(),vc.end());
    for(int i = 1; i <= n; i++)
        par[i] = i, ran[i] = 1;
    total = 0;
    for(int i = 0; i < n-1; i++)
    {
        int a = find_par(vc[i].u);
        int b = find_par(vc[i].v);
        total += (ll) ran[a]*ran[b]*vc[i].cost;
        //printf("%d %d %d\n", ran[a], ran[b], vc[i].cost);
        if(ran[a]>ran[b])
        {
            par[b] = a;
            ran[a] += ran[b];
        }
        else
        {
            par[a] = b;
            ran[b] += ran[a];
        }
    }
}

int main()
{
    int te, ti, u, v, w, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        vc.clear();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            vc.push_back(data(u,v,w));
        }
        mst(n);
        printf("%lld\n", total*2);
    }
    return 0;
}

