#include<cstdio>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

vector <int> adj[200];
int flag[200];
int bfs(int n);
int main()
{
    int test;
    int vert, edges;
    int f, t;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &vert, &edges);
        for(int i = 0; i <= vert; i++)
            adj[i].clear();
        memset(flag, 0, sizeof (flag));
        for(int i = 0; i < edges; i++)
        {
            scanf("%d %d", &f, &t);
            adj[f].push_back(t);
            adj[t].push_back(f);
        }
        int total = 0, k;
        for(int i = 0; i < vert; i++)
        {
            if(flag[i] == 0)
            {
                k = bfs(i);
                if(k == -1)
                {
                    total = -1;
                    break;
                }
                else
                {
                    total += k;
                }
            }
        }
        printf("%d\n", total);
    }
    return 0;
}

int bfs(int n)
{
    queue <int > next;
    int one = 1, two = 0;
    int i, j, k;
    int siz;
    next.push(n);
    flag[n] = 1;
    while(!next.empty())
    {
        n = next.front();
        next.pop();
        siz = adj[n].size();
        for(i = 0; i < siz; i++)
        {
            k = adj[n][i];
            if(flag[k] == 0)
            {
                next.push(k);
                if(flag[n] == 1)
                {
                    flag[k] = 2;
                    two++;
                }
                else
                {
                    flag[k] = 1;
                    one++;
                }
            }
            else if(flag[n] == flag[k])
                return -1;
        }
    }
    if(two == 0 || two > one)
        return one;
    return two;
}
