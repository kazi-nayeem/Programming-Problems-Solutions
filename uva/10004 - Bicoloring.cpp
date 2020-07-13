#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
using namespace std;

vector <int > adj[205];
queue <int> next;
int flag[205];
int bfs(void);
int main()
{
    int i;
    int m, n;
    int edg;
    int vertices;
    while(scanf("%d", &vertices) == 1)
    {
        if(vertices == 0) break;
        for(i = 0; i <= vertices; i++)
            adj[i].clear();
        scanf("%d", &edg);
        for(i = 0; i < edg; i++)
        {
            scanf("%d %d", &n, &m);
            adj[n].push_back(m);
            adj[m].push_back(n);
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
    memset(flag, 0 ,sizeof(flag));
    int i, j, k;
    int siz;
    next.push(0);
    flag[0] = 2;
    while(!next.empty())
    {
        i = next.front();
        next.pop();
        siz = adj[i].size();
        for(j = 0; j < siz; j++)
        {
            k = adj[i][j];
            if(flag[k] == flag[i])
                return 0;
            else if(flag[k] == 0)
            {
                if(flag[i] == 1)
                    flag[k] = 2;
                else
                    flag[k] = 1;
                next.push(k);
            }

        }
    }
    return 1;
}
