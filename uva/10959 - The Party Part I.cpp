#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 1001

using namespace std;

void bfs(int person);

queue < int > next;
vector < int > adj[MAX];
int flag[MAX];

int main()
{
    int time;
    int person, edges;
    int i;
    int a, b;
    flag[0] = 1;
    scanf("%d", &time);
    while(time--)
    {
        scanf("%d%d", &person, &edges);
        for(i = 0; i < edges; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(person);
        for(i = 1; i < person; i++)
        {
            printf("%d\n", flag[i] - 1);
            flag[i] = 0;
        }
        if(time != 0)
            putchar('\n');
    }
    return 0;
}

void bfs(int person)
{
    int i, j;
    int n;
    next.push(0);
    while(!next.empty())
    {
        n = next.front();
        next.pop();
        i = adj[n].size();
        for(int k = 0; k < i; k++)
        {
            j = adj[n][k];
            if((flag[j] > flag[n] + 1) || (flag[j] == 0))
            {
                next.push(j);
                flag[j] = flag[n] + 1;
            }
        }
    }
    for(i = 0; i < person; i++)
        adj[i].clear();
    return;
}
