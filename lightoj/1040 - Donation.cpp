#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MX 55

struct edge{
    int u, v, w;

    bool operator < (const edge &p) const
    {
        return w<p.w;
    }
};

vector<edge> vc;
int parent[MX];

int mst(const int a);
int findpar(const int n);

int main()
{
    edge tem;
    int node, total, time, test;

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d", &node);

        vc.clear();
        total = 0;

        for(int i = 1; i <= node; i++)
            for(int j = 1; j <= node; j++)
        {
            scanf(" %d", &tem.w);
            if(tem.w == 0) continue;

            total += tem.w;
            tem.u = i;
            tem.v = j;
            vc.push_back(tem);
        }
        if(node == 1)
        {
            printf("Case %d: %d\n", test, tem.w);
            continue;
        }
        int di = mst(node);

        if(di == -1)
            printf("Case %d: -1\n", test);
        else
            printf("Case %d: %d\n", test, total - di);
    }
    return 0;
}

int mst(const int a)
{
    for(int i = 0; i <= a; i++) parent[i] = i;
    sort(vc.begin(), vc.end());

    int u, v, co = 0, total = 0;
    int sz = vc.size();

    for(int i = 0; i < sz; i++)
    {
        u = findpar(vc[i].u);
        v = findpar(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            co++;
            total += vc[i].w;
            if(co+1 == a) return total;
        }
    }
    return -1;
}


int findpar(const int n)
{
    if(parent[n] == n) return n;
    return parent[n] = findpar(parent[n]);
}


