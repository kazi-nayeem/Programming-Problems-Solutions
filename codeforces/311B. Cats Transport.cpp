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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct cline {
    ll M, C;
    cline() {}
    cline(ll m, ll c): M(m), C(c) {}
};

//pointer=0,last=0 should be made initially
cline line[MX]; //y=mx+c we need only m(slope) and c(constant)

//Returns true if either line l1 or line l3 is always better than line l2
bool bad(const cline & l1,const cline & l2,const cline & l3) {
    /*
    intersection(l1,l2) has x-coordinate (c1-c2)/(m2-m1)
    intersection(l1,l3) has x-coordinate (c1-c3)/(m3-m1)
    set the former greater than the latter, and cross-multiply to
    eliminate division
    */
    //if the query x values is non-decreasing (reverse(> sign) for vice verse)
    return (l3.C-l1.C)*(l1.M-l2.M)<=(l2.C-l1.C)*(l1.M-l3.M);
}

//Adding should be done serially
//If we want minimum y coordinate(value) then maximum valued m should be inserted first
//If we want maximum y coordinate(value) then minimum valued m should be inserted first
void add(cline l,int &last) {
    //First, let's add it to the end
    line[last++]=l;
    //If the penultimate is now made irrelevant between the antepenultimate
    //and the ultimate, remove it. Repeat as many times as necessary
    //in short convex hull main convex hull tecnique is applied here
    while(last>=3&&bad(line[last-3],line[last-2],line[last-1])) {
        line[last-2]=line[last-1];
        last--;
    }
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line(x) and the lower/upper envelope(pointer)
//This can only be applied if the query of vertical line(x) is already sorted
//works better if number of query is huge
long long query(long long x,int &pointer,int last) {
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

ll dp[MX][2];
ll dist[MX];
ll arr[MX];
ll sum[MX];

ll func(int n, int p) {
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
        sum[i] = arr[i]+sum[i-1];
    for(int i = 1; i <= n; i++) {
        dp[i][1] = i*arr[i]-sum[i];
    }
    for(int k = 2; k <= p; k++) {
        int last = 0, pointer = 0;
        int cur = k&1;
        int prv = (k-1)&1;
        for(int i = k; i <= n; i++) {
            add(cline(-i+1,dp[i-1][prv]+sum[i-1]),last);
            dp[i][cur] = query(arr[i],pointer,last)+i*arr[i]-sum[i];
        }
    }
    return dp[n][p&1];
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 2; i <= n; i++) {
        scanf("%lld", &dist[i]);
        dist[i] += dist[i-1];
    }
    for(int i = 1; i <= m; i++) {
        int pos, tim;
        scanf("%d %d", &pos, &tim);
        arr[i] = tim-dist[pos];
    }
    sort(arr+1,arr+1+m);
    ll res = func(m,k);
    printf("%lld\n", res);
    return 0;
}
