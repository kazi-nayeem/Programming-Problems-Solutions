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
const int MAXN = 215;///total nodes
const int MAXM = 120000;///total edges

int N,edges;
int last[MAXN],prev[MAXM],head[MAXM];
int Cap[MAXM],Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N) {
    edges=0;
    memset(last,-1,sizeof(int)*N);
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u,int v,int cap,int flow) {
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

inline bool dinicBfs(int S,int E,int N) {
    int from=S,to,cap,flow;
    memset(dist,0,sizeof(int)*N);
    dist[from]=1;
    while(!Q.empty()) Q.pop();
    Q.push(from);
    while(!Q.empty()) {
        from=Q.front();
        Q.pop();
        for(int e=last[from]; e>=0; e=prev[e]) {
            to=head[e];
            cap=Cap[e];
            flow=Flow[e];
            if(!dist[to] && cap>flow) {
                dist[to]=dist[from]+1;
                Q.push(to);
                ///Important
                if(to==E) return true;
                ///Need to be sure
            }
        }
    }
    return (dist[E]!=0);
}

inline int dfs(int from,int minEdge,int E) {
    if(!minEdge) return 0;
    if(from==E) return minEdge;
    int to,e,cap,flow,ret;
    for(; nextEdge[from]>=0; nextEdge[from]=prev[e]) {
        e=nextEdge[from];
        to=head[e];
        cap=Cap[e];
        flow=Flow[e];
        if(dist[to]!=dist[from]+1) continue;
        ret=dfs(to,min(minEdge,cap-flow),E);
        if(ret) {
            Flow[e]+=ret;
            Flow[e^1]-=ret;
            return ret;
        }
    }
    return 0;
}

int dinicUpdate(int S,int E) {
    int flow=0;
    while(int minEdge = dfs(S,INF,E)) {
        if(minEdge==0) break;
        flow+=minEdge;
    }
    return flow;
}

int maxFlow(int S,int E,int N) {
    int totFlow=0;
    while(dinicBfs(S,E,N)) {
        for(int i=0; i<=N; i++) nextEdge[i]=last[i]; /// update last edge of ith node
        totFlow+=dinicUpdate(S,E);
    }
    return totFlow;
}

int res[MAXM];
int edg[MAXM];

int main() {
    int te, ti, n, m, N, sink, source;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++) {
        scanf("%d %d", &n, &m);
        N = n+10;
        source = 0;
        sink = n+1;
        init(N);
        int u, v, l, h, tot = 0;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &u, &v, &l, &h);
            tot += l;
            addEdge(source,v,l,0);
            addEdge(u,sink,l,0);
            res[i] = l;
            edg[i] = edges;
            addEdge(u,v,h-l,0);
        }
        addEdge(n,1,INF,0);
        int flo = maxFlow(source,sink,N);
        printf("Case %d: ", te);
        if(tot != flo) {
            printf("no\n");
            continue;
        }
        printf("yes\n");
        for(int i = 0; i < m; i++)
        {
            printf("%d\n", res[i]+Flow[edg[i]]);
        }
    }
    return 0;
}















