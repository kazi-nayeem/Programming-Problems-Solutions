#include<cstdio>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

vector <int> adj[300];
int flag[300];
void bfs(int n);
int bi;
int main()
{
    int vert, edges;
    int f, t;
    while(scanf("%d", &vert) == 1)
    {
        if(vert == 0) break;
        for(int i = 0; i <= vert; i++)
            adj[i].clear();
        memset(flag, 0, sizeof (flag));
        while(scanf("%d %d", &f, &t) == 2)
        {
            if(f == 0 && t == 0) break;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }
        bi = 1;
        for(int i = 0; i < vert; i++)
        {
            if(flag[i] == 0)
            {
                bfs(i);
                if(bi == 0)
                    break;
            }
        }
        if(bi)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

void bfs(int n)
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
                    flag[k] = 2;
                else
                    flag[k] = 1;

            }
            else if(flag[n] == flag[k])
            {
                bi = 0;
                return;
            }
        }
    }
    return;
}
