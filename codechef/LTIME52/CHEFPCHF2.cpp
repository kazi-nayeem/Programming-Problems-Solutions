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
ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

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
const ll base = 10000009ll;
struct data
{
    pii arr[MX];
    ll val[MX];
    int n, k;
    void init(int nn, int kk)
    {
        n = nn;
        k = kk;
        sort(arr,arr+k);
        ll prv = 0;
        for(int i = 0; i < k; i++)
        {
            prv += (arr[i].second*BigMod(base,arr[i].second, mod))%mod;
            prv %= mod;
            val[i] = prv;
        }
    }
    ll getHash(int i, int j)
    {
        int pos1 = lower_bound(arr,arr+k,make_pair(i,0))-arr;
        if(pos1>=k) pos1 = k-1;
        if(arr[pos1].first == i) pos1--;

        int pos2 = lower_bound(arr,arr+k,make_pair(j,0))-arr;
        if(pos2>=k) pos2 = k-1;
        ll res = val[pos2];
        if(pos1>=0)
        {
            res -= val[pos1];
            if(res<0) res += mod;
        }
        res *= BigMod(BigMod(base,i-1,mod), mod-2,mod);
        return res%mod;
    }
};

ll getSum(ll n)
{
    ll k = (n+1)/2;
    ll p = n/2;
    return (k*(k+1)+p*(p+1))/2;
}

data normal, revers;

int getsize(int pos)
{
    int low = 1, hi = min(pos,normal.n-pos+1);
    int ans = 0;
    while(low<=hi)
    {
        int mid = (low+hi)/2;
        int x = pos-mid+1;
        int y = pos+mid-1;
        if(normal.getHash(x,y) == revers.getHash(normal.n-y+1,normal.n-x+1))
        {
            low = mid+1;
            ans = mid;
        }
        else
        {
            hi = mid-1;
        }
    }
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d", &normal.arr[i].first, &normal.arr[i].second);
            revers.arr[i].second = normal.arr[i].second;
            revers.arr[i].first = n-normal.arr[i].first+1;
        }
        normal.init(n,k);
        revers.init(n,k);
        ll ans = 0;
        for(int i = 0; i < k; i++)
        {
            ans += getsize(normal.arr[i].first);
            if(i>0)
            {
                ans += getSum(normal.arr[i].first-normal.arr[i-1].first);
                if(((normal.arr[i].first-normal.arr[i-1].first)%2 == 0) && normal.arr[i].second == normal.arr[i-1].second)
                {
                    ans += getsize((normal.arr[i].first+normal.arr[i-1].first)/2)-(normal.arr[i].first+normal.arr[i-1].first)/2-1;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}































