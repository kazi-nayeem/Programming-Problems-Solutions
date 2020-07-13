#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

const int INF = 2000000000;
const int MAXN = 20200;
const int MAXM = 100200;

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
    last[u]=edges++;

    head[edges] = u;
    prev[edges] = last[v];
    Cap[edges] = 0;
    Flow[edges] = 0;
    last[v]=edges++;

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
        from =Q.front();
        Q.pop();
        for(int e = last[from]; e>= 0; e = prev[e])
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
char arr[105][105];

inline int innode(int r, int c)
{
    return 2*(r*col+c);
}

inline int outnode(int r, int c)
{
    return innode(r,c)+1;
}

int main()
{
    int te, ti, tot;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &row, &col);
        gets(arr[0]);
        for(int i = 0; i < row; i++)
            gets(arr[i]);

        int start = outnode(row,0);
        int sink = outnode(row,2);
        tot = 0;
        init(sink);


        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                addEdge(innode(i,j),outnode(i,j),1,0);
                if(i+1<row)
                {
                    if(arr[i+1][j] != '*')addEdge(outnode(i,j),innode(i+1,j),1,0);
                    if(arr[i][j] != '*') addEdge(outnode(i+1,j),innode(i,j),1,0);
                }
                if(j+1<col)
                {
                    if(arr[i][j+1] != '*') addEdge(outnode(i,j),innode(i,j+1),1,0);
                    if(arr[i][j] != '*') addEdge(outnode(i,j+1),innode(i,j),1,0);
                }
                if(arr[i][j] == '*')
                {
                    addEdge(start,innode(i,j),1,0);
                    tot++;
                }
            }

        for(int i = 0; i < col; i++)
        {
            addEdge(outnode(0,i),sink,1,0);
            addEdge(outnode(row-1,i),sink,1,0);
        }

        for(int i = 1; i < row-1; i++)
        {
            addEdge(outnode(i,0),sink,1,0);
            addEdge(outnode(i,col-1),sink,1,0);
        }

        int res = maxFlow(start,sink,sink+10);

        printf("Case %d: ", te);
        if(res == tot)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}



