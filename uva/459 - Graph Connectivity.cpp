#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

void bfs(int n);

queue < int > next;
vector < int > adj[26];
int flag[26];

int main()
{
    int time, graph;
    int i, j, siz;
    char str[4];
    char vertices, vertex;
    scanf("%d", &time);
    getchar();
    getchar();
    while(time --)
    {
        vertices = getchar();
        getchar();
        while(gets(str))
        {
            if(strlen(str) == 0) break;
            adj[str[0] - 'A'].push_back( str[1] - 'A');
            adj[str[1] - 'A'].push_back( str[0] - 'A');
        }
        for(graph = 0, vertex = 'A'; vertex <= vertices; vertex++)
        {
            if(flag[vertex - 'A'] == 0)
            {
                graph++;
                bfs((int)(vertex - 'A'));
            }
        }
        if(time == 0)
            printf("%d\n", graph);
        else
            printf("%d\n\n", graph);
        memset(flag,0,sizeof(flag));
    }
    return 0;
}

void bfs(int n)
{
    int i, j;
    next.push(n);
    while(!next.empty())
    {
        n = next.front();
        next.pop();
        flag[n] = 1;
        i = adj[n].size();
        for(int k = 0; k < i; k++)
        {
            j = adj[n][k];
            if(flag[j] == 0)
                next.push(j);
        }
        adj[n].clear();
    }
    return;
}

