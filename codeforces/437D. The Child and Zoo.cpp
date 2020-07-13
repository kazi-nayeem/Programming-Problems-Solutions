#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MX 100005
typedef long long ll;

struct data{
    int pos, val;
    bool operator < (const data & p) const
    {
        return val < p.val;
    }
};

vector<int> adj[MX];
char flag[MX];
int parent[MX];
int person[MX];
data weight[MX];
int node, edge;

int find_parent(int n)
{
    if(n == parent[n]) return n;
    return parent[n] = find_parent(parent[n]);
}

ll func()
{
    for(int i = 0; i <= node; i++)
    {
        parent[i] = i;
        person[i] = 1;
    }
    sort(weight+1, weight+node+1);

    ll res = 0;
    for(int i = node; i >= 1; i--)
    {
        ll val = weight[i].val;
        int u = weight[i].pos;
        flag[u] = 1;
        for(int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j];
            if(flag[v] == 0) continue;
            int pu = find_parent(u);
            int pv = find_parent(v);
            if(pu == pv) continue;
            res += (ll) val*person[pu]*person[pv];
            person[pu] += person[pv];
            person[pv] = 0;
            parent[pv] = pu;
        }
    }
    return res;
}

int main()
{
    scanf("%d %d", &node, &edge);
    for(int i = 1; i <= node; i++)
    {
        scanf("%d", &weight[i].val);
        weight[i].pos = i;
    }
    int u, v;
    for(int i = 0; i < edge; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll res1 = func();
    double res = (double) res1/node;
    res =(double) res/(node-1);
    res *= 2.0;
    //cout<< res <<endl;
    printf("%.8lf\n", res);
    return 0;
}
