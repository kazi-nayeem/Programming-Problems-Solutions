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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll,ll> pii;

struct P
{
    ll x, y, z;
    P(ll xt = 0, ll yt = 0, ll zt = 0)
    {
        x = xt;
        y = yt;
        z = zt;
    }
};

struct Comparator
{
    bool operator ()(const P &a, const P &b) const
    {
        if(a.y != b.y) return a.y<b.y;
        return a.x<b.x;
    }
};

const int S = 105000;

P p[S];

bool com(P a, P b)
{
    return (a.x != b.x) ? (a.x < b.x):(a.y<b.y);
}

inline ll sqr(ll a)
{
    return a*a;
}

ll SD(P a, P b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}

pii ClosestPair(int n)
{
    int left,right,ci,cj,i;
    ll dis,m;
    set<P,Comparator> st;
    P tmp;
    __typeof(st.begin()) itl, ith;
    sort(p,p+n,com);
    for(int i = 0; i < n; i++) p[i].z = i;
    ci = p[0].z;
    cj = p[1].z;
    m = SD(p[0],p[1]);
    st.insert(p[0]);
    st.insert(p[1]);
    left = 0;
    right = 2;

    while(right<n)
    {
        while(left<right && sqr(p[left].x-p[right].x)>=m)
        {
            st.erase(p[left]);
            left++;
        }
        dis = sqrt(m)+1e-15;
        itl = st.lower_bound(P(p[right].x,p[right].y-dis));
        ith = st.upper_bound(P(p[right].x,p[right].y+dis));

        while(itl != ith)
        {
            dis = SD(*itl,p[right]);
            if(dis<m)
            {
                m = dis;
                ci = itl->z;
                cj = p[right].z;
            }
            itl++;
        }
        st.insert(p[right]);
        right++;

    }
    return pii(ci,cj);
}

int main()
{
    ll total = 0;
    int n, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        total += x;
        p[i-1] = P(i,total);
    }
    pii res = ClosestPair(n);
    printf("%I64d\n", SD(p[res.first],p[res.second]));
    return 0;
}


