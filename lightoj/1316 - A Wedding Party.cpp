//C headers
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>

//C++ headers
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

#define MX 505
#define INF 1000

struct data{
    int v, w, mask, shop;
    data(){}
    data(int node, int weight, int msk, int shp):v(node),w(weight),mask(msk),shop(shp){}
    bool operator < (const data & p) const
    {
        if(shop != p.shop) return shop<p.shop;
        return p.w<w;
    }
};
struct data2{
    int v, w;
    data2(){}
    data2(int node, int weight):v(node),w(weight) {}
};

map<int,int> mp[MX];
vector<data2> adj[MX];
int shoppos[MX], sp;

int dijkstra(int node)
{
    priority_queue<data> qu;
    qu.push(data(0,0,0,0));
    mp[0][0] = 0;
    sp = -1;
    int res = -1;
    while(!qu.empty())
    {
        int u, w, msk, sh;
        u = qu.top().v;
        w = qu.top().w;
        msk = qu.top().mask;
        sh = qu.top().shop;
        qu.pop();

        if(u == node)
        {
            if(sh>sp)
            {
                sp = sh;
                res = w;
            }
            else if(sh == sp && res > w)
                res = w;
            continue;
        }
        if(mp[u][msk] < w) continue;
        if(shoppos[u] != -1 && (((msk >> shoppos[u])&1) == 0))
        {
            sh++;
            msk = msk | (1<<shoppos[u]);
        }
        int v, tw, sz = adj[u].size();
        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].v;
            tw = adj[u][i].w+w;
            if(mp[v].find(msk) == mp[v].end())
            {
                mp[v][msk] = tw;
                qu.push(data(v,tw,msk,sh));
            }
            else if(mp[v][msk] > tw)
            {
                mp[v][msk] = tw;
                qu.push(data(v,tw,msk,sh));
            }
        }
    }
    return res;
}

int main()
{
    int te, ti, node, edge, shop, u, v, w;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &node, &edge, &shop);
        for(int i = 0; i <= node; i++)
        {
            mp[i].clear();
            adj[i].clear();
        }
        memset(shoppos, -1, sizeof shoppos);
        for(int i = 0; i < shop; i++)
        {
            scanf("%d", &u);
            shoppos[u] = i;
        }
        for(int i = 0; i < edge; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(data2(v,w));
        }
        int res = dijkstra(node-1);
        if(res == -1)
            printf("Case %d: Impossible\n", te);
        else
        {
            if(shoppos[node-1] != -1) sp++;
            printf("Case %d: %d %d\n", te, sp, res);
        }
    }
    return 0;
}

