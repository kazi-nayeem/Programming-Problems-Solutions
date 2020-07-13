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
#define MXN 100005
#define step 20
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int n, parent[MXN][step+1],start[MXN], finish[MXN],T;
int save[MXN][step+1][10];

vector<int> adj[MXN];
vector<int> people[MXN];

void marge(int c[10], int b[10], int a[10])
{
    int p = 0, q = 0;
    for(int i = 0; i < 10; i++)
    {
        while(a[p] == b[q] && a[p] < 1000000) p++;
        if(a[p] < b[q])
        {
            c[i] = a[p++];
        }
        else
        {
            c[i] = b[q++];
        }
    }
}

int tem1[10];
int tem2[10];

void dfs(int u, int p)
{
    int i, v;
    start[u] = T++;
    sort(people[u].begin(), people[u].end());

    memset(tem1,1,sizeof tem1);
    memset(tem2,1,sizeof tem2);
    for(int i = 0; i < 10 && i < people[u].size(); i++)
        tem1[i] = people[u][i];
    //for(int i = 0; i < 10 && i < people[p].size(); i++)
    // tem2[i] = people[p][i];

    parent[u][0] = p;
    marge(save[u][0],tem1,tem2);
    /*printf("----%d-----\n", u);
    for(int j = 0; j < 3; j++)
        printf("%d ", save[u][0][j]);
    puts("");*/
    for(int i = 1; i <= step; i++)
    {
        parent[u][i] = parent[parent[u][i-1]][i-1];
        marge(save[u][i],save[u][i-1],save[parent[u][i-1]][i-1]);
        /*puts("");
        for(int j = 0; j < 3; j++)
            printf("%d ", save[parent[u][i-1]][i-1][j]);
        puts("");
        for(int j = 0; j < 3; j++)
            printf("%d ", save[u][i][j]);
        puts("");*/
    }
    //puts("-----------\n\n");
    for(int i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if(v == p) continue;
        dfs(v,u);
    }
    finish[u] = T++;
}

bool IsAnchestor(int u, int v)
{
    return (start[u]<=start[v] && finish[u]>=finish[v]);
}

int lca_query(int u, int v)
{
    int w = -1, temp = u;
    if(IsAnchestor(u,v)) return u;
    if(IsAnchestor(v,u)) return v;

    for(int i = step; i>= 0; i--)
        if(!IsAnchestor(parent[temp][i],v))
            temp = parent[temp][i];
    return parent[temp][0];
}

int res[10];

void query(int lca, int u)
{
    memset(res,1,sizeof res);
    int w = -1, temp = u;
    for(int i = step; i>= 0; i--)
        if(!IsAnchestor(parent[temp][i],lca))
        {
            for(int j = 0; j < 10; j++)
                tem1[j] = res[j];
            marge(res,tem1,save[temp][i]);
            temp = parent[temp][i];
        }
    for(int i = 0; i < 10; i++)
        tem1[i] = res[i];
    marge(res,tem1,save[temp][0]);
    return;
}

set<int> fina;
vector<int> vt;

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        people[x].push_back(i);
    }
    memset(save,1,sizeof save);
    //printf("%d\n", save[0][0][0]);
    dfs(1,1);
    for(int l = 0; l < q; l++)
    {
        int u, v, a;
        scanf("%d %d %d", &u, &v, &a);
        int lca = lca_query(u,v);
        //puts("-----");
        fina.clear();
        vt.clear();
        query(lca,u);
        for(int i = 0; i < 10; i++)
        {
            //printf("%d ", res[i]);
            if(res[i] <= m)
                vt.push_back(res[i]);
        }
        //puts("ok");
        query(lca,v);
        for(int i = 0; i < 10; i++)
        {
            //printf("%d ", res[i]);
            if(res[i] <= m)
                vt.push_back(res[i]);
        }
        for(int i = 0; i < 10 && i < people[lca].size(); i++)
        {
            //printf("%d ", res[i]);
            vt.push_back(people[lca][i]);
        }
        for(int i = 0; i < vt.size(); i++)
        {
            //printf("%d ", res[i]);
            fina.insert(vt[i]);
        }
        //puts("jd");
        printf("%d", min((int)fina.size(),a));
        for(set<int> :: iterator it = fina.begin(); it != fina.end() && a > 0; it++, a--)
            printf(" %d", *it);
        puts("");
    }
    return 0;
}

