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
using namespace std;

#define ll long long
#define MX 30005
#define inf 100000000
#define step 18

vector<int> adj[MX];
int parent[MX][step+1];
int start[MX], finish[MX], tim;
int genies[MX];
int node, q;
int tree[4*MX];
int lazy[4*MX];

void update(int node, int beg, int en, int i, int j, int val)
{
    if(beg > j || en < i) return;
    if(beg >= i && en <= j)
    {
        tree[node] +=  val * (en-beg+1);
        lazy[node] +=  val;
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (beg+en)/2;
    if(lazy[node] != 0)
    {
        update(left,beg, mid, beg, en, lazy[node]);
        update(right, mid+1, en, beg, en, lazy[node]);
        lazy[node] = 0;
    }
    update(left,beg, mid, i, j, val);
    update(right, mid+1, en, i, j, val);
    tree[node] = tree[left]+tree[right];
    return;
}

int query(int node, int beg, int en, int i, int j)
{
    if(beg > j || en < i) return 0;
    if(beg >= i && en <= j)
        return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (beg+en)/2;
    if(lazy[node] != 0)
    {
        update(left,beg, mid, beg, en, lazy[node]);
        update(right, mid+1, en, beg, en, lazy[node]);
        lazy[node] = 0;
        tree[node] = tree[left]+tree[right];
    }
    int s1 = query(left,beg, mid, i, j);
    int s2 = query(right, mid+1, en, i, j);
    return s1+s2;
}

void lca_dfs_initializer(int u, int p)
{
    start[u] = ++tim;
    parent[u][0] = p;

    for(int i = 0; i < step; i++)
        parent[u][i+1] = parent[parent[u][i]][i];

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        lca_dfs_initializer(v,u);
    }
    finish[u] = tim;
    update(1,0,node,start[u],finish[u],genies[u]);
}

bool IsAnchestor(int u, int v)
{
    if(start[u] <= start[v] && finish[u]>=finish[v]) return true;
    return false;
}

int lca_query(int u, int v)
{
    if(IsAnchestor(u,v)) return u;
    if(IsAnchestor(v,u)) return v;
    int tem = u;
    for(int i = step; i >= 0; i--)
        if(!IsAnchestor(parent[tem][i],v))
            tem = parent[tem][i];
    return parent[tem][0];
}

int dis_query(int u, int v)
{
    int lca = lca_query(u,v);
    int res = query(1,0,node,start[u],start[u]);
    res += query(1,0,node,start[v],start[v]);
    res -= 2*query(1,0,node,start[lca],start[lca]);
    res += genies[lca];
    return res;
}

void lca_update(int u, int x)
{
    update(1,0,node,start[u],finish[u],x-genies[u]);
    genies[u] = x;
    return;
}

void clear_all()
{
    for(int i = 0; i <= node; i++)
        adj[i].clear();
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    tim = 0;
}

int main()
{
    int te, ti, x, u, v;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &node);
        clear_all();
        for(int i = 0; i < node; i++)
            scanf("%d", &genies[i]);
        for(int i = 1; i < node; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        lca_dfs_initializer(0,0);
        scanf("%d", &q);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &x, &u, &v);
            if(x == 0)
                printf("%d\n", dis_query(u,v));
            else
                lca_update(u,v);
        }
    }
    return 0;
}

