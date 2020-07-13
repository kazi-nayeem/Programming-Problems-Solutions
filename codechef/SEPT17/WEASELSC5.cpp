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

struct data
{
    ll m, c ;

    data()
    {
        m = 0 ;
        c = 0 ;
    }
    data(ll m,ll c)
    {
        this->m = m ;
        this->c = c ;
    }

    ll cal_y(ll x)
    {
        return m*x + c ;
    }
};

const int MAXN = MX*4;

data tree[MAXN] ;

void init()
{
    memset(tree,0,sizeof tree);
}

void update(int nd,int l,int r,int i, int j, data line)
{
//    deb(nd,l,r,i,j);
//    deb(line.m, line.c);
    if(l>r) return;
    if(r<i || l>j) return ;
    if(!(i<=l && r <= j))
    {

        int mid = (l+r)/2;
        update(nd*2,l,mid,i,j,line);
        update(nd*2+1,mid+1,r,i,j,line);
        return;
    }
    if(line.cal_y(l)<=tree[nd].cal_y(l) && line.cal_y(r)<=tree[nd].cal_y(r))
    {
        tree[nd] = line;
//        deb("replace",nd, l, r, i, j);
//        deb(line.m, line.c);
        return;
    }
    if(line.cal_y(l)>=tree[nd].cal_y(l) && line.cal_y(r)>=tree[nd].cal_y(r))
    {
        return;
    }
    if(l == r) return;
    //deb("not");
    int mid = (l+r)/2;
    //if(line.cal_y(l) < tree[nd].cal_y())
    if(line.cal_y(l) >= tree[nd].cal_y(l) && line.cal_y(mid) >= tree[nd].cal_y(mid))
    {
        update(nd*2+1,mid+1,r,i,j,line);
        return;
    }
    if(line.cal_y(mid+1) >= tree[nd].cal_y(mid+1) && line.cal_y(r) >= tree[nd].cal_y(r))
    {
        update(nd*2,l,mid,i,j,line);
        return;
    }
    update(nd*2+1,mid+1,r,i,j,line);
    update(nd*2,l,mid,i,j,line);
}

ll query(int nd,int l,int r,int x)
{
    if(l>x || r <x) return mod*mod;
//    if(x == 2)
//    {
//        deb("query", nd, l, r, x);
//        deb("found ", nd, tree[nd].m, tree[nd].c);
//    }
    if(l == r)
    {
        return tree[nd].cal_y(x);
    }
    int mid = (l+r)/2 ;

    if(mid>=x)
        return min(tree[nd].cal_y(x),query(nd*2,l,mid,x));

    return min(tree[nd].cal_y(x),query(nd*2+1,mid+1,r,x));
}


ll dp[55][MX];
ll arr[MX];
int pre[MX];
int nxt[MX];
vector<int> adj[MX];

void process(int n, int k)
{
    for(int i = 0; i <= n+1; i++) adj[i].clear();
    arr[n+1] = 0;
    arr[0] = 0;
    //deb(">>>>>>");
    pre[0] = 0;
    for(int i = 1; i <= n+1; i++)
    {
        pre[i] = i;
        while(pre[i]>0 && arr[i]<=arr[pre[i]-1]) pre[i] = pre[pre[i]-1];
        //deb(i,arr[i],pre[i]);
    }
    //deb("con>>>");
    nxt[n+1] = n+1;
    for(int i = n; i >= 1; i--)
    {
        nxt[i] = i;
        while(nxt[i]<=n && arr[i]<=arr[nxt[i]+1]) nxt[i] = nxt[nxt[i]+1];
        //deb(i,arr[i],nxt[i]);
        adj[nxt[i]+1].push_back(i);
        //deb(nxt[i]+1,i);
    }
}

ll solve(int n, int k)
{
    process(n,k);
    memset(dp,0,sizeof dp);
    ll ans = 0;
    for(int i = 1; i <= k; i++)
    {
        for(int x = 1; x <= n+1; x++)
        {
            for(int j = 0; j < adj[x].size(); j++)
            {
                int y = adj[x][j];
                dp[i][y] = dp[i-1][x]+(x-y)*arr[y];
            }
        }
        init();
        int total = n+1;
        for(int j = n; j >= 1; j--)
        {
            update(1,1,total,pre[j],j,data(arr[j],-(dp[i][j]+arr[j]*j)));
            //deb(p,query(1,1,total,p));
            dp[i][j] = max(dp[i][j],-query(1,1,total,j));
            //deb("");
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int ti, n, k;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        ll ans = solve(n,k+1);
        reverse(arr+1,arr+1+n);
        ans = max(ans,solve(n,k+1));
        printf("%lld\n", ans);
    }
    return 0;
}
































