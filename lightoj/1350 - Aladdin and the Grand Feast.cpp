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
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 2000000000;
const int MAXN = 350;///total nodes
const int MAXM = 200000;///total edges

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

struct data
{
    char ch;
    int v;
    data(char _c, int _v)
    {
        ch = _c;
        v = _v;
    }
    bool operator < (const data & p) const
    {
        return v < p.v;
    }
};

map<int,int> mp;
int st[110];
int en[110];
int need[110];
int arr[111];
int res[110][110];

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int n, t, c, e;
        scanf("%d %d %d %d", &n, &t, &c, &e);
        int pos = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &st[i], &en[i], &need[i]);
            arr[pos++] = st[i];
            arr[pos++] = en[i];
        }
        arr[pos++] = e;
        arr[pos++] = 1;
        sort(arr,arr+pos);
        mp.clear();
        for(int i = 0; i < pos; i++)
        {
            if(mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = mp.size()-1;
                arr[mp[arr[i]]] = arr[i];
            }
        }
        pos = mp.size();
//        for(int i = 0; i < pos; i++)
//        {
//            printf("%d %d %d\n", i, arr[i], mp[arr[i]]);
//        }

        init(pos+n+10);
        int total = 0;
        for(int i = 1; i <= n; i++)
        {
            total += need[i];
            addEdge(0,i,need[i],0);
        }
        int sink = n+pos+3;
        for(int i = 0; i+1 < pos; i++)
        {
            addEdge(n+i+1,sink,t*c*(arr[i+1]-arr[i]),0);
        }
        memset(res,-1, sizeof res);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j+1 < pos; j++)
            {
                if(st[i]<=arr[j] && en[i] >= arr[j+1])
                {
                    res[i][j] = edges;
                    addEdge(i,n+j+1,arr[j+1]-arr[j],0);
                }
            }
        }
        int flow = maxFlow(0,sink,sink+10);
        //printf("--->%d %d\n", flow, total);
        if(flow != total)
        {
            printf("Case %d: No\n", te);
            continue;
        }
        printf("Case %d: Yes\n", te);
        for(int i = 1; i <= n; i++)
        {
            //printf("%d--> ", i);
            int check = 0;
            for(int j = 0; j < pos; j++)
            {
                if(res[i][j] != -1)
                    {
                        res[i][j] = Flow[res[i][j]];
                        check += res[i][j];
                    }
                //   printf("%d ", res[i][j]);
            }
            assert(check == need[i]);
            // puts("");
        }
        for(int i = 0; i+1 < pos; i++)
        {
            priority_queue<data> qu;
            for(int j = 1; j <= n; j++)
            {
                if(res[j][i] <= 0) continue;
                if(j <= 26)
                    qu.push(data('a'+j-1,res[j][i]));
                else
                    qu.push(data('A'+j-26-1,res[j][i]));
            }
            for(int j = arr[i]; j < arr[i+1]; j++)
            {
                queue<data> tqu;
                for(int tt = 0; tt < t; tt++)
                {
                    if(tt) printf("|");
                    for(int cc = 0; cc < c; cc++)
                    {
                        if(qu.empty())
                            printf(".");
                        else
                        {
                            data now = qu.top();
                            qu.pop();
                            printf("%c", now.ch);
                            now.v--;
                            if(now.v>0)
                                tqu.push(now);
                        }
                    }
                }
                while(!tqu.empty())
                {
                    qu.push(tqu.front());
                    tqu.pop();
                }
                printf("\n");
            }
        }
    }
    return 0;
}















