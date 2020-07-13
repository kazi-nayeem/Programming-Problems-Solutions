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
#define sz              100000+7
#define Mod             100000007
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
#define Read            freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\input.txt","r",stdin)
#define Write           freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\output.txt","w",stdout)
#define num_of_bit(a)   __builtin_popcount(a) // for long long use ll as suffix
#define lsb(a)          __builtin_ffs(a) // for long long use ll as suffix
#define msb(a)          32-__builtin_clz(a) // for long long use ll as suffix
#define inf             1000000000000000007LL

// typedef

typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<jora_int> VJ ;
typedef vector<jora_ll> VJL ;

//debug

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

// moves

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//close

#define MAXN 4000000+7

struct data
{
    ll m , c ;
    int l , r ;

    data()
    {
        m = 0 ;
        c = 0 ;
        l = -1 ;
        r = -1 ;
    }
    data(ll m,ll c)
    {
        this->m = m ;
        this->c = c ;
        l = -1 ;
        r = -1 ;
    }

    ll cal_y(ll x)
    {
        return m*x + c ;
    }
};


data tree[MAXN] ;
int id ;

void init()
{
    id = 0;
    tree[0] = data();
}

int update(int nd,int l,int r,data line)
{
    if(nd == -1)
    {
        tree[id] = line ;
        return id++;
    }

    if(tree[nd].cal_y(l)<=line.cal_y(l) && tree[nd].cal_y(r)<=line.cal_y(r))
        return nd ;

    if(line.cal_y(l)<=tree[nd].cal_y(l) && line.cal_y(r) <= tree[nd].cal_y(r))
    {
        tree[id] = tree[nd] ;
        tree[id].c = line.c ;
        tree[id].m = line.m ;
        return id++;
    }

    int mid = (l+r)/2 , lc = tree[nd].l , rc = tree[nd].r ;
    int nnd = id++ ;

    tree[nnd] = tree[nd] ;

    if(tree[nnd].cal_y(l)>line.cal_y(l))
        swap(tree[nnd].c,line.c) , swap(tree[nnd].m,line.m) ;

    if(tree[nnd].cal_y(mid) < line.cal_y(mid)) tree[nnd].r = update(tree[nnd].r,mid+1,r,line) ;

    else
    {
        swap(tree[nnd].c,line.c) , swap(tree[nnd].m,line.m) ;
        tree[nnd].l = update(tree[nnd].l,l,mid,line);
    }

    return nnd ;
}

ll query(int nd,int l,int r,int x)
{
    if(nd == -1)
        return inf ;

    int mid = (l+r)/2 ;

    if(mid>=x)
        return min(tree[nd].cal_y(x),query(tree[nd].l,l,mid,x));

    return min(tree[nd].cal_y(x),query(tree[nd].r,mid+1,r,x));
}

int arr_a[sz] , arr_b[sz] ;

int main()
{
    int root = -1 , n , total = 1000000000 ;

    sf1(n);

    for(int i=0 ; i<n ; i++)
        sf1(arr_a[i]);

    for(int i=0 ; i<n ; i++)
        sf1(arr_b[i]);

    root = update(root,1,total,data(arr_b[0],0)) ;

    ll ans = 0 ;

    for(int i=n-1 ; i>=0 ; i--)
    {
        ans = query(root,1,total,arr_a[i]);
        root = update(root,1,total,data(arr_b[i],ans));
    }

    init();
    root = -1;
    total = 1000000000;
    root = update(root,1,total,data(arr_b[0],0)) ;

    ans = 0 ;

    for(int i=1 ; i<n ; i++)
    {
        ans = query(root,1,total,arr_a[i]);
        root = update(root,1,total,data(arr_b[i],ans));
    }

    printf("%lld\n",ans);

    return 0 ;
}
