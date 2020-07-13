#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define inf 1000000000

vector<int> adj[1005];
int cost[1005];
int total[1005];

int main()
{
    int node, edge;
    scanf("%d%d", &node, &edge);
    for(int i = 1; i <= node; i++)
        scanf("%d", &cost[i]);
    int a, b;
    for(int i = 0; i < edge; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        total[a] += cost[b];
        total[b] += cost[a];
    }
    int ans = 0;
    for(int i = 1; i < node; i++)
    {
        int mx = -1, now = 0;
        for(int j = 1; j <= node; j++)
        {
            if(cost[j] > mx)
            {
                now = j;
                mx = cost[j];
            }
            /*else if(total[j] == mx && cost[now] < cost[j])
            {
                now = j;
                mx = total[j];
            }
            else if(total[j] == mx && cost[now] == cost[j] && adj[j].size() < adj[now].size())
            {
                now = j;
                mx = total[j];
            }*/
        }
        if(now == 0) break;
//        printf("%d %d\n", now, total[now]);
        ans += total[now];
        for(int j = 0; j < adj[now].size(); j++)
            {
                if(total[adj[now][j]]>0 && total[adj[now][j]] != inf)
                total[adj[now][j]] -= cost[now];
            }
        cost[now] = -2;
    }
    printf("%d\n", ans);
}
