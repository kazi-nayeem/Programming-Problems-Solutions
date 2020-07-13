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

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
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
#define MX  100005
#define inf 100000000

const ll mod = 10000000000007ll;


struct data{
    ll u, v, w;
    data(ll u, ll v, ll w): u(u), v(v), w(w) {}
    data(){}
    bool operator == (const data & p) const
    {
        return u == p.u && v == p.v && w == p.w;
    }
};

data edge[2][MX];
vector<pll> adj[2][MX];
ll dist[MX];
ll sum[MX];
ll child[MX];

void nor_dfs(int u, int p)
{
    child[u]++;
    for(int i = 0; i < adj[0][u].size(); i++)
    {
        int v = adj[0][u][i].first;
        if(v == p) continue;
        nor_dfs(v,u);
        ll w = adj[0][u][i].second;
        w *= child[v];
        w += dist[v];
        sum[u] += child[u]*w+child[v]*dist[u];
        dist[u] += w;
        child[u] += child[v];
    }
}

void dfs(int k, int u, int p, ll cost)
{
    //deb(">>>", k, u, p, cost);
    dist[u] = min(dist[u],cost);
    for(int i = 0; i < adj[k][u].size(); i++)
    {
        int v = adj[k][u][i].first;
        if(v == p) continue;
        ll w = adj[k][u][i].second+cost;
        dfs(k,v,u,w);
    }
}


int main()
{
//    freopen("input.txt", "r", stdin);
    int ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
        {
            adj[0][i].clear();
            adj[1][i].clear();
            dist[i] = mod;
        }
        for(int i = 0; i < 2; i++)
            for(int j = 1; j < n; j++)
            {
                ll u, v, w;
                scanf("%lld %lld %lld", &u, &v, &w);
                edge[i][j] = data(u,v,w);
                adj[i][u].push_back(make_pair(v,w));
                adj[i][v].push_back(make_pair(u,w));
            }
        bool chec = true;
        for(int i = 1; i < n && chec; i++)
        {
            chec = edge[0][i] == edge[1][i];
        }
        if(chec)
        {
            memset(child,0,sizeof child);
            memset(dist,0,sizeof dist);
            memset(sum,0,sizeof sum);
            nor_dfs(1,1);
            ll ans = 0;
            for(int i = 1; i <= n; i++)
                ans += sum[i];
            printf("%lld\n", ans);
            continue;
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            dfs(0,i,i,0);
            dfs(1,i,i,0);
            for(int j = 1; j <= n; j++)
            {
                //deb(i,j,dist[j]);
                ans += dist[j];
                dist[j] = mod;

            }
        }
        printf("%lld\n", ans/2);
    }
    return 0;
}































