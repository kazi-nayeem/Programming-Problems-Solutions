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
#define MX  200005
#define inf 100000000

const ll mod = 1000000007ll;

pii tree[MX*4];
int lazy[MX*4];
int arr[MX];
int arr2[MX];

void init(int n, int b, int e) {
    if(b == e) {
        tree[n] = make_pair(0,0);
        if(arr[b]) tree[n].second++;
        else tree[n].first++;
        lazy[n] = 0;
        return;
    }
    int m = (b+e)/2;
    int l = n<<1;
    int r = l+1;
    init(l,b,m);
    init(r,m+1,e);
    lazy[n] = 0;
    tree[n].first = tree[l].first+tree[r].first;
    tree[n].second = tree[l].second+tree[r].second;
}

void update(int n, int b, int e, int i, int j) {
    if(b>j || e<i) return;
    if(i<= b && e <= j) {
        swap(tree[n].first,tree[n].second);
        lazy[n]++;
        lazy[n] %= 2;
        return;
    }
    int m = (b+e)/2;
    int l = n<<1;
    int r = l+1;
    if(lazy[n] == 1) {
        update(l,b,m,b,e);
        update(r,m+1,e,b,e);
        lazy[n] = 0;
        tree[n].first = tree[l].first+tree[r].first;
        tree[n].second = tree[l].second+tree[r].second;
    }
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    lazy[n] = 0;
    tree[n].first = tree[l].first+tree[r].first;
    tree[n].second = tree[l].second+tree[r].second;
}

int query(int n, int b, int e, int i, int j) {
    if(b>j || e<i) return 0;
    if(i<= b && e <= j) {
        return tree[n].second;
    }
    int m = (b+e)/2;
    int l = n<<1;
    int r = l+1;
    if(lazy[n] == 1) {
        update(l,b,m,b,e);
        update(r,m+1,e,b,e);
        lazy[n] = 0;
        tree[n].first = tree[l].first+tree[r].first;
        tree[n].second = tree[l].second+tree[r].second;
    }
    return query(l,b,m,i,j)+query(r,m+1,e,i,j);
}

vector<int> adj[MX];
int start[MX];
int fini[MX];
int tim;

void dfs(int u, int p) {
    start[u] = ++tim;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,u);
    }
    fini[u] = tim;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    freopen("00.txt", "r", stdin);
    int n, x;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &x);
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr2[i]);
    dfs(1,1);
    for(int i = 1; i <= n; i++) {
        arr[start[i]] = arr2[i];
    }
    init(1,1,n);
    int q;
    scanf("%d", &q);
    char str[1000];
    while(q--) {
        scanf("%s %d", str, &x);
        if(str[0] == 'g') {
            printf("%d\n", query(1,1,n,start[x],fini[x]));
        } else {
            update(1,1,n,start[x],fini[x]);
        }
    }
    return 0;
}






























