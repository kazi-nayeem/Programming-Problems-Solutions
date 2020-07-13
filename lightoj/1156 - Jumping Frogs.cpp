
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


const int INF = 200000000;
const int MAXN = 300;
const int MAXM = 10000;

int edges;
int last[MAXN], Prev[MAXM], head[MAXM];
int Cap[MAXM], Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];

queue<int> Q;

void init(int N)
{
    edges = 0;
    memset(last,-1,sizeof(int)*N);
}

inline void addEdge(int u, int v, int cap, int flow)
{
    head[edges] = v;
    Prev[edges] = last[u];
    Cap[edges] = cap;
    Flow[edges] = flow;
    last[u] = edges++;

    head[edges] = u;
    Prev[edges] = last[v];
    Cap[edges] = cap;
    Flow[edges] = flow;
    last[v] = edges++;
}

inline bool dinicBfs(int S, int E, int N)
{
    int from = S, to, cap,flow;
    memset(dist,0,sizeof(int)*N);
    dist[from] = 1;
    while(!Q.empty()) Q.pop();
    Q.push(from);

    while(!Q.empty())
    {
        from = Q.front();
        Q.pop();

        for(int e = last[from]; e>= 0; e = Prev[e])
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
    int to,e,cap,flow,ret;
    for(; nextEdge[from] >= 0; nextEdge[from] = Prev[e])
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

int dinicUpdate(int S,int E)
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

int in(int n)
{
    return 2*n;
}
int out(int n)
{
    return 2*n+1;
}

int capacity[MAXN];
int pos[MAXN], totalDis;

bool canPass(int dis, int n)
{
    init(n*2+40);
    int start = in(n+1);
    int st = out(n+1);
    int sink = out(n+2);
    addEdge(start,st,2,0);
    if(dis >= totalDis) addEdge(st,sink,2,0);
    for(int i = 0; i < n; i++)
    {
        addEdge(in(i),out(i),capacity[i],0);
        if(pos[i] <= dis)
            addEdge(st,in(i),2,0);
        if(pos[i]+dis >= totalDis)
            addEdge(out(i),sink,2,0);
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(pos[i]-pos[j] <= dis && pos[i] > pos[j])
                addEdge(out(j),in(i),2,0);
        }
    }
    int maxf = maxFlow(start,sink,sink+10);

    return maxf>=2;
}

int binary(int n)
{
    int st = 1;
    int en = totalDis+2;
    int mid;
    while(st <= en)
    {
        mid = (st+en)/2;
        if(canPass(mid,n)) en = mid-1;
        else st = mid+1;
    }
    if(!canPass(en,n)) en++;
    return en;
}

int main()
{
    int te, ti, n;
    char str[5];
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &totalDis);
        for(int i = 0; i < n; i++)
        {
            scanf(" %2s %d", str, &pos[i]);
            if(str[0] == 'B') capacity[i] = 2;
            else capacity[i] = 1;
        }
        /*for(int i = 1; i <= totalDis; i++)
        {
            if(canPass(i,n)) printf("%d yes\n", i);
        }*/
        printf("Case %d: %d\n", te, binary(n));
    }
    return 0;
}












