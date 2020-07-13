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
#define MX  1000005
#define MXS  1005
#define inf 100000000ll

const ll mod = 1000000007ll;

struct Vector
{
    ll arr[MXS];
    int sz;
    void clear()
    {
        sz = 0;
    }
    void add(ll a)
    {
        arr[sz++] = a;
    }
    ll getLast()
    {
        if(sz == 0) return -inf;
        return arr[sz-1];
    }
    int getPos(ll a)
    {
        int pos = lower_bound(arr,arr+sz,a)-arr;
        //if(pos<sz && arr[pos] == a) pos++;
        return pos;
    }
    int getMXCover(ll a)
    {
        int pos = lower_bound(arr,arr+sz,a)-arr;
        pos++;
        return pos;
    }
};

int segsz, totalseg;
Vector seg[MXS];
ll arr[MX];
int nxt[MXS];
int nxt_pos[MXS];

void update(int n, int p, ll x)
{
    int curseg = p/segsz;
    arr[p] += x;
    seg[curseg].clear();
    stack<int> st;
    for(int i = 0; i < curseg; i++)
    {
        if(nxt[i]>=curseg)
        {
            st.push(i);
        }
    }
    for(int i = curseg*segsz; i<n && (i < ((curseg+1)*segsz)); i++)
    {
        if(arr[i]>seg[curseg].getLast())
        {
            while(!st.empty() && seg[st.top()].getLast()<arr[i])
            {
                nxt[st.top()] = curseg;
                nxt_pos[st.top()] = seg[curseg].sz;
                st.pop();
            }
            seg[curseg].add(arr[i]);
        }
    }
    nxt[curseg] = totalseg+1;
    nxt_pos[curseg] = segsz;
    for(int i = curseg+1; i < totalseg; i++)
    {
        if(seg[i].getLast()<=seg[curseg].getLast()) continue;
        nxt[curseg] = i;
        nxt_pos[curseg] = seg[i].getPos(seg[curseg].getLast()+1);
        break;
    }
}

int query(int n, int p, ll l, ll r)
{
    //deb(">>>>>>>>>", p, l, r);
    int ans = 0, i;
    for(i = p; i < n && l<=r; i++)
    {
        if(arr[i]>=l)
        {
            ans++;
            l = arr[i]+1;
        }
        if((i%segsz) == (segsz-1)) break;
    }
    if(r<l || i>=n) return ans;
    //deb("ok", i, l, r, ans);
    i++;
    int curseg = i/segsz;

    while(curseg<totalseg && seg[curseg].getLast()<l) curseg++;

    if(curseg >= totalseg) return ans;
    int stpos = seg[curseg].getPos(l);

    while(curseg<totalseg && l <= r)
    {
        //deb("---", curseg, stpos);
        if(seg[curseg].getLast()>r)
        {
            ans += seg[curseg].getMXCover(r)-stpos;
            break;
        }
        ans += seg[curseg].sz-stpos;
        l = seg[curseg].getLast()+1;
        stpos = nxt_pos[curseg];
        curseg = nxt[curseg];
    }
    return ans;
}

void init(int n)
{
    for(int i = 0; i < MXS; i++)
    {
        seg[i].clear();
        nxt[i] = totalseg+1;
        nxt_pos[i] = segsz;
    }
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        if(i>0 && (i%segsz == 0))
        {
            st.push((i/segsz)-1);
        }
        int pos = i/segsz;
        //deb("i arri seg", i,arr[i],pos);
        if(arr[i]>seg[pos].getLast())
        {
            while(!st.empty() && seg[st.top()].getLast()<arr[i])
            {
                nxt[st.top()] = pos;
                nxt_pos[st.top()] = seg[pos].sz;
                st.pop();
            }
            seg[pos].add(arr[i]);
        }
    }
//    for(int i = 0; i < ((n+segsz-1)/segsz); i++)
//        deb(i,seg[i].sz, seg[i].getLast(), nxt[i], nxt_pos[i]);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
    int ti, n, m;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &m);
        segsz = sqrt(n);
        totalseg = (n+segsz-1)/segsz;
        for(int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        init(n);
        while(m--)
        {
            char ch;
            scanf(" %c", &ch);
            if(ch == '?')
            {
                ll i, l, r;
                scanf("%lld %lld %lld", &i, &l, &r);
                int ans = query(n,i-1,l,r);
                //deb("******************");
                printf("%d\n", ans);
            }
            else
            {
                ll i, x;
                scanf("%lld %lld", &i, &x);
                update(n,i-1,x);
            }
        }
    }
    return 0;
}































