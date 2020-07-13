#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

#define MX 1000005

struct edge{int u, v;
        int w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector<edge> vc;
int parent[MX];

int find_parent(int n)
{
    if(parent[n] == n) return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

int mst(int node)
{
    sort(vc.begin(),vc.end());

    for(int i = 1; i <= node; i++) parent[i] = i;

    int sz = (int) vc.size();
    int co = 0;
    for(int i = 0; i < sz; i++)
    {
        int u = find_parent(vc[i].u);
        int v = find_parent(vc[i].v);

        if(u != v)
        {
            co++;
            parent[v] = u;
            if(co+1 == node) return vc[i].w;
        }
    }
    return -1;
}

int main()
{
    int total, sat;
    edge temp;

    while(scanf("%d %d", &sat, &total) == 2)
    {
        if(sat == 0 && total == 0) break;

        for(int i = 0; i < sat; i++) parent[i] = i;

        for(int i = 0; i < total; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);

            vc.push_back(temp);
        }

        int result = mst(sat);

        if(result == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", result);
        vc.clear();

    }
    return 0;
}

