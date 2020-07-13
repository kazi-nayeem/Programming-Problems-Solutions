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

const ll INF = 20000000000000ll;
const ll inf = 20000000000000ll;
const int MAXN = 200;///total nodes
const int MAXM = 100000;///total edges

int N,edges;
int last[MAXN],prev[MAXM],head[MAXM];
ll Cap[MAXM],Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N) {
    edges=0;
    memset(last,-1,sizeof(int)*N);
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u,int v,ll cap,ll flow) {
    //printf("edge add %d %d %lld\n", u, v, cap);
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
    ll from=S,to,cap,flow;
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
            }
        }
    }
    return (dist[E]!=0);
}

inline ll dfs(int from,ll minEdge,int E) {
    if(!minEdge) return 0;
    if(from==E) return minEdge;
    ll to,e,cap,flow,ret;
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

ll dinicUpdate(int S,int E) {
    ll flow=0;
    while(ll minEdge = dfs(S,INF,E)) {
        if(minEdge==0) break;
        flow+=minEdge;
    }
    return flow;
}

ll maxFlow(int S,int E,int N) {
    ll totFlow=0;
    while(dinicBfs(S,E,N)) {
        for(int i=0; i<=N; i++) nextEdge[i]=last[i]; /// update last edge of ith node
        totFlow+=dinicUpdate(S,E);
    }
    return totFlow;
}

int jobtype, worker, regularLow, total_flow;
int vip[1000];
int regu[1000];
int time_need[1000];
vector<int> adj[1000];

bool check_func(ll t) {
    int sourc = 0;
    int regu_sourc = 1;
    int sink = jobtype+jobtype+worker+2;

    init(sink+10);

    addEdge(sourc,regu_sourc,regularLow,0);

    for(int i = 1; i <= worker; i++) {
        addEdge(2*jobtype+i+1,sink,t/time_need[i],0);
    }

    for(int i = 1; i <= jobtype; i++) {
        addEdge(sourc,i+1,vip[i],0);
        addEdge(regu_sourc,i+jobtype+1,regu[i],0);
        for(int j = 0; j < adj[i].size(); j++) {
            addEdge(i+1,adj[i][j]+1+jobtype*2,inf,0);
            addEdge(i+jobtype+1,adj[i][j]+1+jobtype*2,inf,0);
        }
    }
    ll flo = maxFlow(sourc,sink,sink+10);
    //printf("flow %lld %d\n", flo, total_flow);
    return flo>=total_flow;
}

int main() {
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++) {
        scanf("%d %d %d", &jobtype, &worker, &regularLow);
        total_flow = regularLow;
        for(int i = 0; i <= jobtype; i++) {
            adj[i].clear();
        }
        for(int i = 1; i <= worker; i++) {
            scanf("%d", &time_need[i]);
        }

        for(int i = 1; i <= jobtype; i++) {
            int k;
            scanf("%d %d %d", &vip[i], &regu[i], &k);
            total_flow += vip[i];
            while(k--) {
                int x;
                scanf("%d", &x);
                adj[i].push_back(x);
            }
        }
        ll beg = 0, en = 20000000000ll;
        while(beg<=en){
            ll mid = (beg+en)/2;
            if(check_func(mid))
                en = mid-1;
            else
                beg = mid+1;
        }
        printf("Case %d: %lld\n", te, beg);

    }
    return 0;
}









