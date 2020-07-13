//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct cline
{
    ll M, C;
    cline() {}
    cline(ll m, ll c): M(m), C(c) {}
};

//pointer=0,last=0 should be made initially
cline line[MX]; //y=mx+c we need only m(slope) and c(constant)

//Returns true if either line l1 or line l3 is always better than line l2
bool bad(const cline & l1,const cline & l2,const cline & l3)
{
    /*
    intersection(l1,l2) has x-coordinate (c1-c2)/(m2-m1)
    intersection(l1,l3) has x-coordinate (c1-c3)/(m3-m1)
    set the former greater than the latter, and cross-multiply to
    eliminate division
    */
    //if the query x values is non-decreasing (reverse(> sign) for vice verse)
    return (1.0*(l3.C-l1.C)/(l1.M-l3.M))<(1.0*(l2.C-l1.C)/(l1.M-l2.M));
}

//Adding should be done serially
//If we want minimum y coordinate(value) then maximum valued m should be inserted first
//If we want maximum y coordinate(value) then minimum valued m should be inserted first
void add(cline l,int &last)
{
    //First, let's add it to the end
    line[last++]=l;
    //If the penultimate is now made irrelevant between the antepenultimate
    //and the ultimate, remove it. Repeat as many times as necessary
    //in short convex hull main convex hull tecnique is applied here
    while(last>=3&&bad(line[last-3],line[last-2],line[last-1]))
    {
        line[last-2]=line[last-1];
        last--;
    }
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line(x) and the lower/upper envelope(pointer)
//This can only be applied if the query of vertical line(x) is already sorted
//works better if number of query is huge
long long query(long long x,int &pointer,int last)
{
    //If we removed what was the best line for the previous query, then the
    //newly inserted line is now the best for that query
    if (pointer>=last)
        pointer=last-1;
    //Any better line must be to the right, since query values are
    //non-decreasing
    // Min Value wanted... (reverse(> sign) for max value)
    while (pointer<last-1 && line[pointer+1].M*x+line[pointer+1].C<=line[pointer].M*x+line[pointer].C)
        pointer++;
    return line[pointer].M*x+line[pointer].C;
}

//for any kind of query(sorted or not) it can be used
//it works because of the hill property
//works better if number of query is few
long long bs(int st,int end,long long x,int last)
{
    int mid=(st+end)/2;
    // Min Value wanted... (reverse(> sign) for max value)
    if(mid+1<last && line[mid+1].M*x+line[mid+1].C<line[mid].M*x+line[mid].C) return bs(mid+1,end,x,last);
    // Min Value wanted... (reverse(> sign) for max value)
    if(mid-1>=0 && line[mid-1].M*x+line[mid-1].C<line[mid].M*x+line[mid].C) return bs(st,mid-1,x,last);
    return line[mid].M*x+line[mid].C;
}

ll a[MX];
ll b[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
    }
    int last = 0, pointer = 0;
    ll cost = 0;
    add(cline(b[1],0),last);
    for(int i = 2; i <= n; i++)
    {
        cost = query(a[i],pointer,last);
        add(cline(b[i],cost),last);
    }
    printf("%lld\n", cost);
    return 0;
}













