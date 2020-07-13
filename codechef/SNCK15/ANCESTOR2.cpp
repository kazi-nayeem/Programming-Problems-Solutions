// ==========================================================================
//
//                   "With Every Difficulty, There is Relief."
//
// ==========================================================================

// Pre_code

#include <bits/stdc++.h>

// header file

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
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <numeric>
#include <cstring>
//#include <unordered_map>
//#include <unordered_set>

using namespace std ;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;

//define function

#pragma                 comment(linker, "/STACK:667772160")
#define forln(i,a,n)    for(int i=a ; i<n ; i++)
#define foren(i,a,n)    for(int i=a ; i<=n ; i++)
#define forg0(i,a,n)    for(int i=a ; i>n ; i--)
#define fore0(i,a,n)    for(int i=a ; i>=n ; i--)
#define pb              push_back
#define pp              pop_back
#define clr(a,b)        memset(a,b,sizeof(a))
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define pii             acos(-1.0)
#define jora_int        pair<int,int>
#define jora_ll         pair<long long,long long>
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define Max             2000000000+9
#define sz              500000+7
#define Mod             1000000007
#define EPS             1e-7
#define ll              long long
#define ull             unsigned long long
#define fs              first
#define sc              second
#define wait            system("pause")
#define sf              scanf
#define pf              printf
#define mp              make_pair
#define ps              pf("PASS\n")
#define Read            freopen("00.txt","r",stdin)
#define Write           freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\output.txt","w",stdout)
#define num_of_bit(a)   __builtin_popcount(a) // for long long use ll as suffix
#define lsb(a)          __builtin_ffs(a) // for long long use ll as suffix
#define msb(a)          32-__builtin_clz(a) // for long long use ll as suffix
#define inf             10000000000000000LL

// typedef

typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<jora_int> VJ ;
typedef vector<jora_ll> VJL ;

//debug

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<< v <<" ";
        return *this;
    }
} dbg;
#define deb(args...) {dbg,args; cerr<<endl;}


// ---------------------- BEGIN moves ----------------------------------

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
//

// ----------------------------------- END ------------------------------

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

//int set_bit(int n,int pos)
//{
//    return (int)(n|(1<<pos));
//}
//
//int off_bit(int n,int pos)
//{
//    return (int)(n&(~(1<<pos))) ;
//}
//
//bool is_on(int n,int pos)
//{
//    return (bool)(n&(1<<pos));
//}
//
//int flip_bit(int n,int pos)
//{
//    return (int)(n^(1<<pos));
//}

//close

const int LN = 20 ;


int tree[4*sz];


int query_tree(int node,int s,int e,int i,int j)
{
    if(e<i or s>j)
        return 0;

    if(s>=i and e<=j)
        return tree[node];

    int lft = 2*node , rgt = 2*node + 1 , mid = (s+e)/2 ;

    return query_tree(lft,s,mid,i,j)+query_tree(rgt,mid+1,e,i,j)+tree[node];
}

void update_tree(int node,int s,int e,int x,int y, int valu)
{
    if(s>y or e<x)
        return ;

    if(s >= x and e <= x)
    {
        tree[node] += valu ;
        return ;
    }

    int lft = 2*node , rgt = lft+1 , mid = (s+e)/2 ;

    update_tree(lft,s,mid,x,valu);
    update_tree(rgt,mid+1,e,x,valu);
}

vector<int> graph[sz];
vector<int> graph2[sz];
int Tim;
int start[sz];
int fini[sz];

void dfs(int u, int p)
{
    start[u] = ++Tim;
    for(int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(p == v) continue;
        dfs(v,u);
    }
    fini[u] = Tim;
}

int ans[sz];

int n;

void dfs2(int u, int p)
{
    ans[u] = query_tree(1,1,n)
    for(int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(p == v) continue;
        dfs2(v,u);
    }
}


int main()
{
    int tcase ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1(n);
        for(int i=0 ; i<=n ; i++)
        {
            graph[i].clear();
            graph2[i].clear();
        }
        memset(tree,0,sizeof tree);
        for(int i=1 ; i<n ; i++)
        {
            int u , v ;

            sf2(u,v);

            graph[u].pb(v);
            graph[v].pb(u);
        }

        for(int i=1 ; i<n ; i++)
        {
            int u , v ;
            sf2(u,v);
            graph2[u].pb(v);
            graph2[v].pb(u);
        }
        Tim = 0;
    }

    return 0;
}
