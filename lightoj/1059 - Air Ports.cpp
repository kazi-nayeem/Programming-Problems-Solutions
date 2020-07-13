#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define MX 10005

struct edge {int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> vc;
int parent[MX];

int mst(const int cities, const int roads, const int air_ct);
int find_parent(int n);
int airport(const int n);

int main()
{
    int test, time;
    int cities, roads, air_cost;
    int total, air_total;
    edge temp;

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%d %d %d", &cities, &roads, &air_cost);

        for(int i = 1; i <= cities; i++) parent[i] = i;

        for(int i = 0; i < roads; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }
        total = mst(cities, roads, air_cost);
        air_total = airport(cities);

        total += air_total * air_cost;

        printf("Case %d: %d %d\n", test, total, air_total);
        vc.clear();
    }
    return 0;
}

int find_parent(int n)
{
    if(parent[n] == n) return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

int mst(const int cities, const int roads, const int air_ct)
{
    sort(vc.begin(), vc.end());

    int total = 0;
    int u, v;

    for(int i = 0; i < roads; i++)
    {
        if(vc[i].w >= air_ct) break;

        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            total += vc[i].w;
        }
    }
    return total;
}

int airport(const int n)
{
    set<int> st;
    for(int i = 1; i <= n; i++)
        st.insert(find_parent(parent[i]));
    return (int) st.size();
}

