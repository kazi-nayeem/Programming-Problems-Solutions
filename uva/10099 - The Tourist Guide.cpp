#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MX 105

struct edge{int u, v, w;
    bool operator < (const edge& p) const
    {
        return w > p.w;
    }
};

vector<edge> vc;
int parent[MX];

int find_parent(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}

int mst(int start, int finish)
{
    sort(vc.begin(), vc.end());

    int u, v;
    int sz = (int) vc.size();
    for(int i = 0; i < sz; i++)
    {
        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            if(find_parent(start) == find_parent(finish)) return vc[i].w;
        }
    }
    return 0;
}
int main()
{
    int node, road;
    int start, finis, torist;
    int test = 1;

    while(scanf("%d %d", &node, &road) == 2)
    {
        if(node == 0 && road == 0) break;
        vc.clear();
        for(int i = 0; i <= node; i++) parent[i] = i;

        edge temp;

        for(int i = 0; i < road; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }

        scanf("%d %d %d", &start, &finis, &torist);

        int maxi = mst(start, finis);
        int trip = torist / (maxi-1);
        if(trip % maxi) trip++;
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", test++, trip);
    }
    return 0;
}
