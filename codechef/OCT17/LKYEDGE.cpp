#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
//#include <bits/stdc++.h>

using namespace std;

#define HI              printf("HI\n")
#define sf              scanf
#define pf              printf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d)    scanf("%d %d %d %d",&a,&b,&c,&d)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define sf4ll(a,b,c,d)    scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define forln(i,a,n)    for(int i=a ; i<n ; i++)
#define foren(i,a,n)    for(int i=a ; i<=n ; i++)
#define forg0(i,a,n)    for(int i=a ; i>n ; i--)
#define fore0(i,a,n)    for(int i=a ; i>=n ; i--)
#define pb              push_back
#define ppb             pop_back
#define ppf             push_front
#define popf            pop_front
#define ll              long long int
#define ui              unsigned int
#define ull             unsigned long long
#define fs              first
#define sc              second
#define clr( a, b )     memset((a),b,sizeof(a))
#define jora            pair<int, int>
#define jora_d          pair<double, double>
#define jora_ll         pair<long long int, long long int>
#define mp              make_pair
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define PI              acos(0.0)
#define ps              pf("PASS\n")
#define popc(a)         (__builtin_popcount(a))

template<class T1> void deb(T1 e1) {
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2) {
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3) {
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

/// <---------------------------  For Bitmasking  -------------------------------->
//int on( int n, int pos ){
//    return n = n|( 1<<pos );
//}
//bool check( int n, int pos ){
//    return (bool)( n&( 1<<pos ) );
//}
//int off( int n, int pos ){
//    return n = n&~( 1<<pos );
//}
//int toggle( int n, int pos ){
//    return n = n^(1<<pos);
//}
//int count_bit( int n ){
//    return __builtin_popcount( n );
//}
/// <---------------------------  End of Bitmasking  -------------------------------->


/// <--------------------------- For B - Base Number System ----------------------------------->
//int base;
//int pw[10];
//void calPow(int b){
//    base = b;
//    pw[0] = 1;
//    for( int i = 1; i<10; i++ ){
//        pw[i] = pw[i-1]*base;
//    }
//}
//int getV(int mask, int pos){
//    mask /= pw[pos];
//    return ( mask%base );
//}
//int setV(int mask, int v, int pos){
//    int rem = mask%pw[pos];
//    mask /= pw[pos+1];
//    mask = ( mask*base ) + v;
//    mask = ( mask*pw[pos] ) + rem;
//    return mask;
//}
/// <--------------------------- End B - Base Number System ----------------------------------->


// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//double Expo(double n, int p) {
//	if (p == 0)return 1;
//	double x = Expo(n, p >> 1);
//	x = (x * x);
//	return ((p & 1) ? (x * n) : x);
//}

//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MXN 50
#define MXE
#define MXQ
#define SZE
#define MOD
#define EPS
#define INF 100000000
#define MX  10005
#define inf 100000000

const ll mod = 1000000007ll;

struct data {
    int u, id, nxt;
};
int nextEdge[MX];
data Edges[2*MX];
int edgeNo;

void addEdge(int u, int v, int id) {
    Edges[edgeNo].u = v;
    Edges[edgeNo].id = id;
    Edges[edgeNo].nxt = nextEdge[u];
    nextEdge[u] = edgeNo++;
}

//vector<pii> adj[MX];
int par[MX];
int col[MX];
int res[MX];
int m;

int find_par(int u) {
    if(par[u] == -1) return u;
    return par[u] = find_par(par[u]);
}

int next_point[MX];

void init() {
    memset(next_point,0,sizeof next_point);
    memset(res,0,sizeof res);
}

int start[MX], finish[MX], upper_par[MX], upper_edge[MX];
int tim;

void dfs(int u, int p, int no) {
    start[u] = tim++;
    upper_par[u] = p;
    upper_edge[u] = no;
    par[u] = -1;
    for(int i = nextEdge[u]; i != -1; i = Edges[i].nxt) {
        int v = Edges[i].u;
        if(v == p) continue;
        dfs(v,u,Edges[i].id);
    }
    finish[u] = tim++;
}

void update(int u, int v, int id) {
    if(start[u]<=start[v] && finish[v]<=finish[u]) return;
    int pu = find_par(u);
    if(pu == u) {
        int edg = upper_edge[u];
        next_point[edg] = 0;
        res[edg] += m-id+1;
        par[u] = upper_par[u];
        pu = find_par(u);
    }
    update(pu,v,id);
}

pii edge[MX];

void calc(int st) {
    //init();
    memset(start,-1,sizeof start);
    memset(par,-1,sizeof par);
    memset(nextEdge,-1,sizeof nextEdge);
    edgeNo = 0;
    for(int i = st; i <= m; i++) {
        if(next_point[i] == -1) continue;
        next_point[i] = -1;
        int u = edge[i].first;
        int v = edge[i].second;
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv) col[i] = 1;
        else {
            col[i] = 0;
            par[pu] = pv;
            //adj[u].push_back(make_pair(v,i));
            addEdge(u,v,i);
            addEdge(v,u,i);
            //adj[v].push_back(make_pair(u,i));
        }
    }
    tim = 1;
    for(int i = st; i <= m; i++) {
        int u = edge[i].first;
        if(start[u] != -1) continue;
        dfs(u,u,-1);
    }
    for(int i = st; i <= m; i++) {
        if(col[i] == 1) {
            int u = edge[i].first;
            int v = edge[i].second;
            update(u, v, i);
            update(v, u, i);
            next_point[i] = 0;
            res[i] += m-i+1;
        }
    }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
    int ti;
    scanf("%d", &ti);
    while(ti--) {
        init();
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &edge[i].first, &edge[i].second);
        for(int i = 1; i < m; i++) {
            calc(i);
        }
        printf("%d", res[1]);
        for(int i = 2; i <= m; i++)
            printf(" %d", res[i]);
        puts("");
    }
    return 0;
}
