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

#define MX 200005
#define inf 1500000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

map<int , int> xx, yy;
vector<pair<int,int> > vc[MX];

pair<int,int> Prev[MX], nex[MX];

pair<int,int> tree[MX*4];
int used[MX];

void init(int node, int beg, int en) {
    if(beg == en) {
        used[beg] = 0;
        tree[node] = make_pair(vc[beg][used[beg]].first,beg);
        return;
    }
    int mid = (beg+en)/2;
    init(node*2,beg,mid);
    init(node*2+1,mid+1,en);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}

pll query(int node, int beg, int en, int i, int j) {
    if(beg>=i && j >= en) return tree[node];

    int mid = (beg+en)/2;
    if(j <= mid) return query(node*2,beg,mid,i,j);
    if(i > mid) return query(node*2+1,mid+1,en,i,j);
    pii a = query(node*2,beg,mid,i,j);
    pii b = query(node*2+1,mid+1,en,i,j);
    return min(a,b);
}

void update(int node, int beg, int en, int i) {
    if(beg>=i && i >= en) {
        tree[node] = make_pair(vc[beg][used[beg]].first,beg);
        return;
    }
    int mid = (beg+en)/2;
    if(i <= mid) update(node*2,beg,mid,i);
    if(i > mid) update(node*2+1,mid+1,en,i);
    tree[node] = min(tree[node*2],tree[node*2+1]);
    return;
}

int res[MX];
int path[MX];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &Prev[i].first, &Prev[i].second,&nex[i].first, &nex[i].second);
        xx[Prev[i].first] = i;
        xx[nex[i].first] = i;
        yy[nex[i].second] = i;
        yy[Prev[i].second] = i;
    }
    xx[0] = 0;
    yy[0] = 0;
    xx[inf] = inf;
    yy[inf] = inf;
    int cc = 0;
    for(auto &i : xx) {
        i.second = cc++;
    }
    cc = 0;
    for(auto &i : yy) {
        i.second = cc++;
    }
    for(int i = 0; i <= n; i++) {
        Prev[i].first = xx[Prev[i].first];
        nex[i].first = xx[nex[i].first];
        Prev[i].second = yy[Prev[i].second];
        nex[i].second = yy[nex[i].second];
        //printf("%d %d %d %d\n", Prev[i].first, Prev[i].second,nex[i].first, nex[i].second);
        vc[Prev[i].first].push_back(make_pair(Prev[i].second,i));
    }
    for(int i = 0; i <= 2*n; i++) {
        vc[i].push_back(make_pair(inf,-1));
        sort(vc[i].begin(),vc[i].end());
    }
    //puts("ok");
    init(1,0,2*n);

    /*for(int i = 0; i < 15; i++){
        printf("%d %d\n", tree[i].first, tree[i].second);
    }*/
    queue<int> qu;
    qu.push(0);
    res[0] = 1;
    while(!qu.empty()) {
        int pos = qu.front();
        qu.pop();
        while(true) {
            pii now = query(1,0,2*n,0,nex[pos].first);
            if(now.first>nex[pos].second) break;
            int tes = vc[now.second][used[now.second]].second;
            if(res[tes] == 0) {
                qu.push(tes);
                res[tes] = res[pos]+1;
                path[tes] = pos;
            }
            used[now.second]++;
            update(1,0,2*n,now.second);
        }
    }
   // for(int i = 0; i <= n; i++){
     //   printf("i %d %d\n", res[i],path[i]);
    //}
    if(res[n] == 0){
        puts("-1");
        return 0;
    }
    printf("%d\n", res[n]-1);
    stack<int> st;
    st.push(n);
    while(path[st.top()] > 0){
        st.push(path[st.top()]);
    }
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}


