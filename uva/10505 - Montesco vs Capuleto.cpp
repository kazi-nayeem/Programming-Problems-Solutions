#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int flag[202];
vector<int> adj[202];
void bfs(int n);
int point;

int main()
{
    int test;
    int vertices, one, two;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &vertices);
        for(int i = 1; i <= vertices; i++)
        {
            int total;
            scanf("%d", &total);
            for(int j = 0; j < total; j++)
            {
                int c;
                scanf("%d", &c);
                adj[i].push_back(c);
                adj[c].push_back(i);
            }
        }
        int maximum = 0;
        for(int i = 1; i <= vertices; i++)
        {
            if(flag[i] == 0)
            {
                bfs(i);
                for(i = 1, one = 0, two = 0; i <= vertices; i++)
                {
                    if(flag[i] == 1)
                    {
                        one++;
                        flag[i] == 3;
                    }
                    else if(flag[i] == 2)
                    {
                        two++;
                        flag[i] = 3;
                    }
                }
            }
            if(point == 1)
            {
                if(one > two)
                    maximum += one;
                else
                    maximum += two;
            }
        }
        printf("%d\n", maximum);
        for(int i = 0; i <= vertices; i++)
            adj[i].clear();
        memset(flag, 0, sizeof flag);
    }
    return 0;
}

void bfs(int n)
{
    queue <int> next;
    point = 1;
    next.push(n);
    flag[n] = 1;
    while(!next.empty())
    {
        n = next.front();
        next.pop();
        int siz = adj[n].size();
        for(int i = 0; i < siz; i++)
        {
            int j = adj[n][i];
            if(flag[j] == 0)
            {
                next.push(j);
                if(flag[n] == 1)
                    flag[j] = 2;
                else
                    flag[j] = 1;
            }
            else if(flag[n] == flag[j])
                point = 0;
        }
    }
    return;
}
