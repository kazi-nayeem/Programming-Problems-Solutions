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
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define mem(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 0x3f3f3f3f
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

///V*E^2 Complexity
///Base doesn't matter

const int MAXN = 350;///total nodes
const int MAXM = 220200;///total edges

int edges;
///edge info
int last[MAXN];
int Prev[MAXM],head[MAXM];
int Cap[MAXM];
int Cost[MAXM];

int Flow[MAXN];
int edgeNo[MAXN];
int dist[MAXN];
int par[MAXN];
bool visited[MAXN];

void init(int N)
{
    memset(last,-1,sizeof(int)*N);
    edges=0;
}

void addEdge(int u,int v,int cap,int cost)
{
    head[edges]=v;
    Prev[edges]=last[u];
    Cap[edges]=cap;
    Cost[edges]=cost;
    last[u]=edges++;

    head[edges]=u;
    Prev[edges]=last[v];
    Cap[edges]=0;
    Cost[edges]=-cost;
    last[v]=edges++;
}

queue<int> Q;
int ans;
pair<int,int> SPFA(int S,int E,int N)
{
    int totFlow=0,totCost=0;
    while(!Q.empty()) Q.pop();
    int u,v,cap,cost;
    while(true)
    {
        Flow[S]=oo;
        //memset(dist,0x3f3f3f3f,sizeof(int)*N);
        for(int i = 0; i <= N; i++)
            dist[i] = oo;
        dist[S]=0;
        memset(visited,false,sizeof(bool)*N);
        visited[S]=1;
        Q.push(S);
        //puts("---------");
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            //printf("%d\n", u);
            visited[u]=false;
            for(int e=last[u]; e>=0; e=Prev[e])
            {
                v=head[e];
                cap=Cap[e];
                cost=Cost[e];
                if(cap&&dist[v]>dist[u]+cost)
                {
                    dist[v]=dist[u]+cost;
                    Flow[v]=min(Flow[u],cap);
                    edgeNo[v]=e;
                    par[v]=u;
                    if(!visited[v])
                    {
                        visited[v]=true;
                        Q.push(v);
                    }
                }
            }
        }
        if(dist[E]==oo) break;
        totCost+=dist[E]*Flow[E];
        totFlow+=Flow[E];
        for(int i=E; i!=S; i=par[i])
        {
            Cap[edgeNo[i]]-=Flow[E];
            Cap[edgeNo[i]^1]+=Flow[E];
        }
        ans = min(totCost,ans);
    }
    return mp(totFlow,totCost);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int x;
    int source = 0, sink = n+m+5;
    init(sink+2);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        addEdge(0,i,x,0);
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        addEdge(i+n,sink,x,0);
        for(int j = 1; j <= n; j++)
            addEdge(i+n,sink,1,(j*j)-((j-1)*(j-1)));
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &x);
            addEdge(i,j+n,1,-x);
        }
    ans = 0;
    SPFA(source,sink,sink+2);
    printf("%d\n", -ans);
    return 0;
}















