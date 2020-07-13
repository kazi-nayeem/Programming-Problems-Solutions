#include<cstdio>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

int bfs(void);
vector<int> adj[200];
queue<int> next;
int flag[200];
int main()
{
    int vertices, edges;
    while(scanf("%d", &vertices) == 1 && (vertices != 0))
    {
        for(int i = 0; i < vertices; i++)
            adj[i].clear();
        scanf("%d", &edges);
        for(int i = 0; i < edges; i++)
        {
            int m, n;
            scanf("%d %d", &m, &n);
            adj[m].push_back(n);
            adj[n].push_back(m);
        }
        if(bfs() == 1)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}

int bfs(void)
{
    while(!next.empty())
        next.pop();
    memset(flag, 0, sizeof(flag));
    next.push(0);
    flag[0] = 1;
    while(!next.empty())
    {
        int i = next.front();
        next.pop();
        int siz = adj[i].size();
        for(int j = 0; j < siz; j++)
        {
            int k = adj[i][j];
            if(flag[k] == 0)
            {
                next.push(k);
                if(flag[i] == 1)
                    flag[k] = 2;
                else
                    flag[k] = 1;
            }
            else if(flag[k] == flag[i])
                return 0;
        }
    }
    return 1;
}
