#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MX 200005

struct edge{int u, v, w;
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
    return parent[n] = find_parent(parent[n]);
}

int mst(int node)
{
    sort(vc.begin(), vc.end());

    int total = 0, count = 0, u, v;
    int sz = (int) vc.size();

    for(int i = 0; i < sz; i++)
    {
        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            count++;
            total += vc[i].w;
            if(count+1 == node) return total;
        }
    }
    return total;
}
int main()
{
    int node, road;
    while(scanf("%d %d", &node, &road) == 2)
    {
        if(node == 0 && road == 0) break;

        for(int i = 0; i <= node; i++) parent[i] = i;

        int total = 0;
        edge temp;

        for(int i = 0; i < road; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            total += temp.w;
            vc.push_back(temp);
        }

        printf("%d\n", total-mst(node));
        vc.clear();
    }
    return 0;
}

