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

#define SZ(x) ((int)x.size())
#define mem(name,val) memset(name,(val),sizeof(name));
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 2000000000;
const int MAXN = 300;///total nodes
const int MAXM = 40000;///total edges

int N,edges;
int last[MAXN],Prev[MAXM],head[MAXM];
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
    Prev[edges]=last[u];
    Cap[edges]=cap;
    Flow[edges]=flow;
    last[u]=edges++;

    head[edges]=u;
    Prev[edges]=last[v];
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
        for(int e=last[from]; e>=0; e=Prev[e])
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
    for(; nextEdge[from]>=0; nextEdge[from]=Prev[e])
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

vector<int> adj[MAXN];
int xx[MAXN];
int yy[MAXN];
int arr[MAXN];
int capaci[MAXN];


int in(int n)
{
    return 2*n;
}

int out(int n)
{
    return 2*n+1;
}

double distanc(int x1, int y1, int x2, int y2)
{
    return (double) sqrt((double) (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    int te, ti, n;
    double dis;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int mx= 0;
        scanf("%d %lf", &n, &dis);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &xx[i], &yy[i], &arr[i], &capaci[i]);
            adj[i].clear();
            mx += arr[i];
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(dis>=distanc(xx[i],yy[i],xx[j],yy[j]))
                {
                    adj[i].push_back(j);
                }
            }
        int st = out(n+1);
        int sink = out(n+2);
        vector<int> res;
       // printf("ok");
        for(int i = 0; i < n; i++)
        {
            init(sink+5);
            addEdge(in(i),sink,INF,0);
            for(int j = 0; j < n; j++)
            {
                addEdge(st,in(j),arr[j],0);
                if(i == j) continue;
                addEdge(in(j),out(j),capaci[j],0);

                for(int k = 0; k < adj[j].size(); k++)
                {
                    addEdge(out(j),in(adj[j][k]),INF,0);
                }
            }
            //printf("ok");
            if(mx == maxFlow(st,sink,sink+5))res.push_back(i);
        }
        printf("Case %d:", te);
        if(res.size() == 0) res.push_back(-1);
        for(int i = 0; i < res.size(); i++)
            printf(" %d", res[i]);
        puts("");
    }
    return 0;
}













