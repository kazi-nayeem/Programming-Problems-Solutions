#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MX 105

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

int mst(int node, int a, int b)
{
    for(int i = 0; i <= node; i++) parent[i] = i;

    int total = 0, count = 0, u, v;
    int sz = (int) vc.size();

    for(int i = a; i < sz && i >= 0; i += b)
    {
        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            count++;
            total += vc[i].w;
            if(count == node) return total;
        }
    }
    return total;
}
int main()
{
    int node, time, test;

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d", &node);

        edge temp;

        while(scanf("%d %d %d", &temp.u, &temp.v, &temp.w) == 3)
        {
            if(temp.u == 0 && temp.v == 0 && temp.w == 0) break;

            vc.push_back(temp);
        }

        sort(vc.begin(), vc.end());

        int total = mst(node, 0, 1);
        total += mst(node, (vc.size()) - 1, -1);
        if(total & 1)
            printf("Case %d: %d/2\n", test, total);
        else
            printf("Case %d: %d\n", test, total>>1);
        vc.clear();
    }
    return 0;
}

