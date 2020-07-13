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
#define wait            system("pause")
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

const ll mod = 1000000007ll;

ll tree[MX*4];

void updatetree(int n, int b, int e, int i, int j, ll val)
{
    if(e<i || j<b) return;
    if(i <= b && e <= j)
    {
        tree[n] += val;
        return;
    }
    int m = (b+e)/2;
    updatetree(n*2,b,m,i,j,val);
    updatetree(n*2+1,m+1,e,i,j,val);
}

ll sumquery(int n, int b, int e, int p)
{
    if(b>p || e < p) return 0;
    if(b == e) return tree[n];
    int m = (b+e)/2;
    return tree[n]+sumquery(n*2,b,m,p)+sumquery(n*2+1,m+1,e,p);
}

struct data
{
    int x, y;
    ll w;
    data(int x, int y, ll w): x(x), y(y), w(w) {}
    bool operator < (const data & p) const
    {
        return w>p.w;
    }
};

int n, m;
ll dist[5][MX];
ll down[5][MX];
ll righ[5][MX];
int par[5][MX];

void dijkstra(int p, int q, int s, int t)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dist[i][j] = mod*mod;
    priority_queue<data> qu;
    dist[p][q] = 0;
    qu.push(data(p,q,dist[p][q]));

    while(!qu.empty())
    {
        p = qu.top().x;
        q = qu.top().y;
        ll w = qu.top().w;
        qu.pop();

        if(dist[p][q]<w) continue;
        if(s == p && q == t) return;
        if(p<n)
        {
            int tx = p+1;
            int ty = q;
            ll tw = w+down[p][q];
            if(dist[tx][ty]>tw)
            {
                dist[tx][ty] = tw;
                par[tx][ty] = 0;
                qu.push(data(tx,ty,tw));
            }
        }

        if(q<m)
        {
            int tx = p;
            int ty = q+1;
            ll tw = w+righ[p][q];
            if(dist[tx][ty]>tw)
            {
                dist[tx][ty] = tw;
                par[tx][ty] = 1;
                qu.push(data(tx,ty,tw));
            }
        }

        if(p>1)
        {
            int tx = p-1;
            int ty = q;
            ll tw = w+down[tx][ty];
            if(dist[tx][ty]>tw)
            {
                dist[tx][ty] = tw;
                par[tx][ty] = 2;
                qu.push(data(tx,ty,tw));
            }
        }

        if(q>1)
        {
            int tx = p;
            int ty = q-1;
            ll tw = w+righ[tx][ty];
            if(dist[tx][ty]>tw)
            {
                dist[tx][ty] = tw;
                par[tx][ty] = 3;
                qu.push(data(tx,ty,tw));
            }
        }
    }
}

ll val[5][MX];

void update(int x1, int y1, int x2, int y2, ll c)
{
    if(n == 1)
    {
        updatetree(1,1,m,min(y1,y2),max(y1,y2),c);
        return;
    }
    dijkstra(x1,y1,x2,y2);
    //deb(x1,y1,x2,y2);
    while(x2 != x1 || y2 != y1)
    {
        //deb(x2,y2);
        val[x2][y2] += c;
        if(par[x2][y2] == 1)
        {
            y2--;
        }else if(par[x2][y2] == 0){
            x2--;
        }else if(par[x2][y2] == 2){
            x2++;
        }else if(par[x2][y2] == 3){
            y2++;
        }
    }
    val[x1][y1]+=c;
    //deb(x1,y1);
}

ll query(int x, int y)
{
    if(n == 1) return sumquery(1,1,m,y);
    return val[x][y];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int q, ty;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n-1; i++)
        for(int j = 1; j <= m; j++)
            scanf("%lld", &down[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m-1; j++)
            scanf("%lld", &righ[i][j]);
    //return 0;
    while(q--)
    {
        scanf("%d", &ty);
        if(ty == 1)
        {
            pii a, b;
            ll c;
            scanf("%d %d %d %d %lld", &a.first, &a.second, &b.first, &b.second, &c);
            update(a.first, a.second, b.first, b.second, c);
        }else{
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(x,y));
        }
    }
    return 0;
}



