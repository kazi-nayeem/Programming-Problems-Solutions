#include <queue>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

#define ll long long

///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 2000000000;
const int MAXN = 220;///total nodes
const int MAXM = 6000;///total edges

int N,edges;
int last[MAXN],prev[MAXM],head[MAXM];
int Cap[MAXM],Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N)
{
    edges=0;
    memset(last,-1,sizeof(int)*N);
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u,int v,int cap,int flow)
{
    head[edges]=v;
    prev[edges]=last[u];
    Cap[edges]=cap;
    Flow[edges]=flow;
    last[u]=edges++;

    head[edges]=u;
    prev[edges]=last[v];
    Cap[edges]=0;
    Flow[edges]=0;
    last[v]=edges++;
}

inline bool dinicBfs(int S,int E,int N)
{
    int from=S,to,cap,flow;
    memset(dist,0,sizeof(int)*N);
    dist[from]=1;
    while(!Q.empty()) Q.pop();
    Q.push(from);
    while(!Q.empty())
    {
        from=Q.front();
        Q.pop();
        for(int e=last[from]; e>=0; e=prev[e])
        {
            to=head[e];
            cap=Cap[e];
            flow=Flow[e];
            if(!dist[to] && cap>flow)
            {
                dist[to]=dist[from]+1;
                Q.push(to);
            }
        }
    }
    return (dist[E]!=0);
}

inline int dfs(int from,int minEdge,int E)
{
    if(!minEdge) return 0;
    if(from==E) return minEdge;
    int to,e,cap,flow,ret;
    for(; nextEdge[from]>=0; nextEdge[from]=prev[e])
    {
        e=nextEdge[from];
        to=head[e];
        cap=Cap[e];
        flow=Flow[e];
        if(dist[to]!=dist[from]+1) continue;
        ret=dfs(to,min(minEdge,cap-flow),E);
        if(ret)
        {
            Flow[e]+=ret;
            Flow[e^1]-=ret;
            return ret;
        }
    }
    return 0;
}

int dinicUpdate(int S,int E)
{
    int flow=0;
    while(int minEdge = dfs(S,INF,E))
    {
        if(minEdge==0) break;
        flow+=minEdge;
    }
    return flow;
}

int maxFlow(int S,int E,int N)
{
    int totFlow=0;
    while(dinicBfs(S,E,N))
    {
        for(int i=0; i<=N; i++) nextEdge[i]=last[i]; /// update last edge of ith node
        totFlow+=dinicUpdate(S,E);
    }
    return totFlow;
}

int phase1[105];
int phase2[105];
int res[100][100];
int n, m;
int row[105][105];
int col[105][105];

int in(int i)
{
    return 2*i;
}

int out(int i)
{
    return 2*i + 1;
}

void solve(void)
{
    int start = 0;
    int sink = 2*(n+m)+3;
    init(sink+10);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            int ph1 = i+j-1;
            int ph2 = i+m-j;
            phase1[ph1]--;
            phase2[ph2]--;
            //printf("%d %d\n", ph1, ph2);
            row[ph1][ph2] = i;
            col[ph1][ph2] = j;
            int u = ph1;
            int v = ph2+m+n;
            addEdge(u,v,99,0);
            //printf("%d %d %d\n", u, v, 99);
            //mp[make_pair(u,v)] = make_pair(i,j);

        }
    for(int i = 1; i < m+n; i++)
    {
        addEdge(start,i,phase1[i],0);
        //printf("%d %d %d\n", start, i, phase1[i]);
        addEdge(i+m+n,sink,phase2[i],0);
        //printf("%d %d %d\n", i+m+n, sink, phase2[i]);
    }
    int res1 = maxFlow(start,sink,sink+10);
    //printf("%d\n", res1);
    memset(res,0,sizeof res);
    for(int i = 1; i < m+n; i++)
    {
        for(int e = last[i]; e >= 0; e = prev[e])
        {
            if(e&1) continue;
            int v = head[e];
            res[row[i][v-n-m]][col[i][v-n-m]] += Flow[e];
        }
    }
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i < n+m; i++)
            scanf("%d", &phase1[i]);
        for(int i = 1; i < n+m; i++)
            scanf("%d", &phase2[i]);
        solve();
        printf("Case %d:\n", te);
        for(int i = 1; i <= n; i++)
        {
            printf("%d", res[i][1]+1);
            for(int j = 2; j <= m; j++)
                printf(" %d", res[i][j]+1);
            puts("");
        }
        //if(te < ti) puts("");
    }
    return 0;
}













