#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;

#define MX 35

vector<int> adj[MX];
int flag[MX];

int bfs(const int s, const int f);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti, node, edge, test, weight;
    map<string,int> mp;
    char str1[10], str2[10];
    printf("SHIPPING ROUTES OUTPUT\n");
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        printf("\nDATA SET  %d\n\n", te);
        mp.clear();
        scanf("%d %d %d", &node, &edge, &test);
        for(int i = 1; i <= node; i++)
        {
            scanf(" %s", str1);
            adj[i].clear();
            mp[str1] = i;
        }
        for(int i = 0; i < edge; i++)
        {
            scanf(" %s %s", str1, str2);
            int a = mp[str1], b = mp[str2];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0; i < test; i++)
        {
            scanf(" %d %s %s", &weight, str1, str2);
            int a = mp[str1], b = mp[str2];
            int k = bfs(a,b);
            if(k == -1)
                printf("NO SHIPMENT POSSIBLE\n");
            else
                printf("$%d\n", k * weight * 100);
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}

int bfs(const int s, const int f)
{
    for(int i = 0; i < MX; i++) flag[i] = -1;
    queue<int> qu;
    int a, w, sz, b;
    flag[s] = 0;
    qu.push(s);
    while(!qu.empty())
    {
        a = qu.front();
        qu.pop();

        w = flag[a];
        sz = adj[a].size();
        for(int i = 0; i < sz; i++)
        {
            b = adj[a][i];
            if(b == f) return w+1;
            if(flag[b] != -1) continue;
            flag[b] = w+1;
            qu.push(b);
        }
    }
    return -1;
}
