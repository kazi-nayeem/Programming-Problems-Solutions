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

int row, col;
int res[100][100];
int rowcom[100], rowsum;
int colcom[100], colsum;

int solve()
{
    int st = 0;
    int sink = row+col+2;
    init(sink+10);
    for(int i = 1; i <= row; i++)
    {
        addEdge(st,i,rowcom[i],0);
        for(int j = 1; j <= col; j++)
        {
            addEdge(i,j+row,1,0);
        }
    }
    for(int j = 1; j <= col; j++)
    {
        addEdge(j+row,sink, colcom[j],0);
    }
    int flow = maxFlow(st,sink,sink+10);
    if(flow != rowsum)
        return -1;
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            for(int e = last[i]; e >= 0; e = prev[e])
            {
                if(head[e] != j+row) continue;

                if(Flow[e] == 0)
                {
                    Flow[e] = Cap[e] = 0;
                    Flow[e^1] = Cap[e^1] = 0;
                    res[i][j] = 0;
                    break;
                }


                int fs = edges;
                addEdge(st,i,1,0);
                int se = edges;
                addEdge(j+row,sink,1,0);

                Flow[e] = Cap[e] = 0;
                Flow[e^1] = Cap[e^1] = 0;
                int fl = maxFlow(st,sink,sink+10);

                if(fl == 0)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = 0;
                }

                Flow[fs] = Cap[fs] = 0;
                Flow[fs^1] = Cap[fs^1] = 0;

                Flow[se] = Cap[se] = 0;
                Flow[se^1] = Cap[se^1] = 0;
                break;
            }
        }
    }
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &row, &col);
        rowsum = colsum = 0;
        for(int i = 1; i <= row; i++)
        {
            scanf("%d", &rowcom[i]);
            rowsum += rowcom[i];
        }
        for(int i = 1; i <= col; i++)
        {
            scanf("%d", &colcom[i]);
            colsum += colcom[i];
        }

        printf("Case %d:", te);
        if(rowsum != colsum)
        {
            printf(" impossible\n");
            continue;
        }
        int res1 = solve();

        if(res1 == -1)
        {
            printf(" impossible\n");
            continue;
        }

        for(int i = 1; i <= row; i++)
        {
            puts("");
            for(int j = 1; j <= col; j++)
                printf("%d", res[i][j]);
        }
        puts("");
    }
    return 0;
}

