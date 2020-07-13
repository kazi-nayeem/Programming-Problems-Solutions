#include<cstring>
#include<cstdio>
#include<map>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

int bfs(int n, int l);
map <string, int > nodes;
queue<int > next;
vector<int> adj[40];
int flag[40];

int main()
{
    //freopen("input.txt", "r", stdin);
    char str1[100], str2[100];
    int n;
    int i, j;
    int dis;
    int test = 1;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        i = 1;
        getchar();
        while(n--)
        {
            scanf(" %s %s", str1, str2);
            if(nodes.find(str1) == nodes.end())
            {
                    nodes[str1] = i++;
            }
            if(nodes.find(str2) == nodes.end())
            {
                nodes[str2] = i++;
            }
            adj[nodes[str1]].push_back(nodes[str2]);
            adj[nodes[str2]].push_back(nodes[str1]);
        }
        i--;
        while(scanf(" %s %d", str1, &dis) == 2)
        {
            if(dis == 0)
            {
                if(str1[0] == '0' && str1[1] == '\0')
                    break;
            }
            if(nodes.find(str1) == nodes.end())
                printf("Case %d: %d nodes not reachable from node %s with TTL = %d.\n", test++, i, str1, dis);
            else
                printf("Case %d: %d nodes not reachable from node %s with TTL = %d.\n", test++, i - bfs(nodes[str1], dis), str1, dis);
        }
        nodes.clear();
        for(j = 0; j <= i; j++)
            adj[j].clear();
    }
    return 0;
}

int bfs(int n, int l)
{
    //printf("n = %d\n", n);
    memset(flag,0,sizeof(flag));
    l++;
    int i, j, k;
    int siz, total = 0;
    next.push(n);
    flag[n] = 1;
    while(!next.empty())
    {
        i = next.front();
        next.pop();
        if(flag[i] <= l)
                total++;
        siz = adj[i].size();
        for(j = 0; j < siz; j++)
        {
            k = adj[i][j];
            if(flag[k] == 0)
            {
                //printf("%d\n", k);
                next.push(k);
                flag[k] = flag[i] + 1;
            }
        }
    }
    //printf("tiat = %d\n", total);
    return total;
}

