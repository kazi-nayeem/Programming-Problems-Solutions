#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MX 1000005

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
    int node, flag = 0;
    while(scanf("%d", &node) == 1)
    {
        if(flag) putchar('\n');
        flag = 1;
        for(int i = 0; i <= node; i++) parent[i] = i;

        int total = 0, u, v, w;
        edge temp;

        for(int i = 1; i < node; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            total+= w;
        }

        int k;
        scanf("%d", &k);

        for(int i = 0; i < k; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }

        int m;
        scanf("%d", &m);

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }

        printf("%d\n%d\n", total, mst(node));
        vc.clear();
    }
    return 0;
}
