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

int tree[9*sz] , chainInd[sz] , chainHead[sz] , nodeInd[sz] , nodeIndcst[sz] ,
 subsize[sz] , parent[sz][21] , otherEnd[sz] , depth[sz] , n , chain_num , ptr ;
vector<int>graph[sz] , cost[sz] , id[sz] ;
VI graph2[sz] ;

void dfs(int par,int cur,int dep)
{
    subsize[cur] = 1 ;
    depth[cur] = dep ;
    parent[cur][0] = par ;

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        int v = graph[cur][i] ;

        if(v != par)
        {
            otherEnd[id[cur][i]] = v ;
            dfs(cur,v,dep+1);
            subsize[cur] += subsize[v] ;
        }
    }
}

void build_lca()
{
    for(int i=1 ; (1<<i)<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(parent[j][i-1] != -1)
                parent[j][i] = parent[parent[j][i-1]][i-1] ;
        }
    }
}

int LCA(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);

    for(int i=LN ; i>=0 ; i--)
    {
        if((depth[u]-(1<<i))>=depth[v])
            u = parent[u][i] ;
    }

    if(u == v)
        return u ;

    for(int i=LN ; i>=0 ; i--)
    {
        if(parent[u][i] != -1 and parent[u][i] != parent[v][i])
        {
            u = parent[u][i] ;
            v = parent[v][i] ;
        }
    }

    return parent[u][0] ;
}

void hld(int par,int cur,int cst)
{
    if(chainHead[chain_num] == -1)
        chainHead[chain_num] = cur ;

    chainInd[cur] = chain_num ;
    nodeInd[cur] = ptr ;
    nodeIndcst[ptr++] = cst ;

    int special = -1 , ct = -1 ;

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        int v = graph[cur][i] ;

        if(v != par)
        {
            if(special == -1 or subsize[v]>ct)
            {
                ct = subsize[v] ;
                cst = cost[cur][i] ;
                special = v ;
            }
        }
    }

    if(special != -1)
    {
        hld(cur,special,cst);
    }

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        int v = graph[cur][i] ;

        if(v != par and v != special)
        {
            chain_num++;
            hld(cur,v,cost[cur][i]);
        }
    }
}

void build_stree(int node,int s,int e)
{
    if(s == e)
    {
        tree[node] = nodeIndcst[s] ;
        return ;
    }

    int lft = node*2 , rgt = 2*node + 1 , mid = (s+e)/2 ;

    build_stree(lft,s,mid);
    build_stree(rgt,mid+1,e);

    tree[node] = tree[lft]+tree[rgt];
}

int query_tree(int node,int s,int e,int i,int j)
{
    if(e<i or s>j)
        return 0;

    if(s>=i and e<=j)
        return tree[node] ;

    int lft = 2*node , rgt = 2*node + 1 , mid = (s+e)/2 ;

    return query_tree(lft,s,mid,i,j)+query_tree(rgt,mid+1,e,i,j);
}

void update_tree(int node,int s,int e,int x,int valu)
{
    if(s>x or e<x)
        return ;

    if(s == x and e == x)
    {
        tree[node] = valu ;
        return ;
    }

    int lft = 2*node , rgt = lft+1 , mid = (s+e)/2 ;

    update_tree(lft,s,mid,x,valu);
    update_tree(rgt,mid+1,e,x,valu);

    tree[node] = tree[lft]+tree[rgt];
}

int query_chain(int u,int v)
{
    if(u == v)
        return query_tree(1,1,ptr,nodeInd[u],nodeInd[v]);

    int uchain , vchain = chainInd[v] , ans = 0 ;

    while(1)
    {
        uchain = chainInd[u] ;

        if(uchain == vchain)
        {
            if(u == v)
                return ans ;

            ans = ans+query_tree(1,1,ptr,nodeInd[v]+1,nodeInd[u]);
            return ans ;
        }

        ans = ans+query_tree(1,1,ptr,nodeInd[chainHead[uchain]],nodeInd[u]);
        u = chainHead[uchain];
        u = parent[u][0] ;
    }
}

int query(int u,int v)
{
    if(u == v)
        return 0 ;

    int anc = LCA(u,v);
//deb(query_chain(u,anc),query_chain(v,anc));
    int ans = query_chain(u,anc)+query_chain(v,anc);

    return ans ;
}

void change(int ind,int valu)
{
    int u = otherEnd[ind] ;
    update_tree(1,1,ptr,nodeInd[u],valu);
}

ll fans[sz]  ;

void fdfs(int u,int p)
{
    fans[u] = query(1,u) ;
    update_tree(1,1,ptr,nodeInd[u],1);

    int v ;

    for(int i=0 ; i<graph2[u].size() ; i++)
    {
        v = graph2[u][i] ;

        if(v == p)
            continue;

        fdfs(v,u);
    }

    update_tree(1,1,ptr,nodeInd[u],0);
}

int main()
{
    int tcase ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        chain_num = 1 ;
        ptr = 1 ;
        sf1(n);

        for(int i=0 ; i<n+7 ; i++)
        {
            graph[i].clear();
            graph2[i].clear();
            cost[i].clear();
            id[i].clear();
            chainHead[i] = -1 ;
            chainInd[i] = -1 ;
            nodeInd[i] = -1 ;
            nodeIndcst[i] = -1 ;
            subsize[i] = 0 ;
            otherEnd[i] = 0 ;
            depth[i] = 0 ;

            for(int k=0 ; k<21 ; k++)
                parent[i][k] = -1 ;
        }

        for(int i=1 ; i<n ; i++)
        {
            int u , v ;

            sf2(u,v);

            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(0);
            cost[v].pb(0);
            id[u].pb(i);
            id[v].pb(i);
        }

        dfs(-1,1,0);
        build_lca();
        hld(-1,1,0);
        build_stree(1,1,ptr);

        for(int i=1 ; i<n ; i++)
        {
            int u , v ;

            sf2(u,v);
            graph2[u].pb(v);
            graph2[v].pb(u);
        }

        fdfs(1,-1);
        for(int i=1 ; i<=n ; i++)
        {
            if(i>1)
                pf(" ");

            pf("%lld",fans[i]);
        }

        pf("\n");
    }

    return 0;
}

/*

13
1 2
1 3
2 4
2 5
3 6
6 7
6 9
7 8
9 10
9 11
11 12
12 13

*/
