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
#define MX 100005
#define inf 100000000

struct data
{
    int u, v;
    data() {}
    data(int a, int b)
    {
        u = a;
        v = b;
    }
};

int dis[205];
int arr[205];
vector<data> vc;

int qube(int a)
{
    return a*a*a;
}

void belm(int node)
{
    memset(dis,21,sizeof dis);
    dis[1] = 0;
    for(int i = 1; i < node; i++)
    {
        for(int j = 0; j < vc.size(); j++)
        {
            int u = vc[j].u;
            int v = vc[j].v;
            if(dis[u] == dis[0]) continue;
            int tem = dis[u]+ qube(arr[v]-arr[u]);
            dis[v] = min(dis[v], tem);
        }
    }
    bool flag = true;
    for(int j = 0; j < vc.size(); j++)
    {
        int u = vc[j].u;
        int v = vc[j].v;
        if(dis[u] == dis[0]) continue;
        int tem = dis[u]+ qube(arr[v]-arr[u]);
        if(dis[v] > tem)
        {
            flag = false;
            break;
        }
    }
    if(flag) return;
    for(int i = 1; i <= node; i++)
        dis[i] = 0;
    return;
}

int main()
{
    int u, v, te, ti, node, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        vc.clear();
        scanf("%d", &node);
        for(int i = 1; i <= node; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            vc.push_back(data(u,v));
        }
        belm(node);
        printf("Case %d:\n", te);
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &u);
            if(dis[u]>=3 && dis[u] != dis[0])
                printf("%d\n", dis[u]);
            else puts("?");
        }
    }
    return 0;
}

