//#include <bits/stdc++.h>

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
#include<map>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

const int INF = 2000000000;
const int MAXN = 505;
const int MAXM = 30005;

int edges;
int last[MAXN], prev[MAXM], head[MAXM];
int Cap[MAXM], Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];

queue<int> Q;

void init(int N)
{
    edges = 0;
    memset(last,-1,sizeof last);
}

inline void addEdge(int u, int v, int cap, int flow)
{
    head[edges] = v;
    prev[edges] = last[u];
    Cap[edges] = cap;
    Flow[edges] = flow;
    last[u] = edges++;

    head[edges] = u;
    prev[edges] = last[v];
    Cap[edges] = 0;
    Flow[edges] = 0;
    last[v] = edges++;
}

inline bool dinicBfs(int S, int E, int N)
{
    int from = S, to, cap, flow;
    memset(dist,0,sizeof dist);
    dist[from] = 1;
    while(!Q.empty()) Q.pop();
    Q.push(from);
    while(!Q.empty())
    {
        from = Q.front();
        Q.pop();
        for(int e = last[from]; e >= 0; e = prev[e])
        {
            to = head[e];
            cap = Cap[e];
            flow = Flow[e];
            if(!dist[to] && cap>flow)
            {
                dist[to] = dist[from]+1;
                Q.push(to);
            }
        }
    }
    return (dist[E] != 0);
}

inline int dfs(int from, int minEdge, int E)
{
    if(!minEdge) return 0;
    if(from == E) return minEdge;
    int to, e, cap, flow, ret;
    for(; nextEdge[from] >= 0; nextEdge[from] = prev[e])
    {
        e = nextEdge[from];
        to = head[e];
        cap = Cap[e];
        flow = Flow[e];
        if(dist[to] != dist[from]+1) continue;
        ret = dfs(to,min(minEdge,cap-flow),E);
        if(ret)
        {
            Flow[e] += ret;
            Flow[e^1] -= ret;
            return ret;
        }
    }
    return 0;
}

int dinicUpdate(int S, int E)
{
    int flow = 0;
    while(int minEdge = dfs(S,INF,E))
    {
        if(minEdge == 0) break;
        flow += minEdge;
    }
    return flow;
}

int maxFlow(int S, int E, int N)
{
    int totFlow = 0;
    while(dinicBfs(S,E,N))
    {
        for(int i = 0; i <= N; i++) nextEdge[i] = last[i];
        totFlow += dinicUpdate(S,E);
    }
    return totFlow;
}

int main()
{
    int te, ti, node, edge, s, e;
    scanf("%d", &ti);
    for(int te = 1; te <= ti; te++)
    {
        scanf("%d %d %d %d", &node, &s, &e, &edge);
        init(node+2);
        for(int i = 0; i < edge; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u,v,w,0);
            addEdge(v,u,w,0);
        }
        printf("Case %d: %d\n", te, maxFlow(s,e,node));
    }
    return 0;
}


