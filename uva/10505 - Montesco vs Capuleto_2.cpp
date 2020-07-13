#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<cstdlib>
using namespace std;
#define MX 201
vector <int> adj[MX];
map<int,int> mp;
int flag[MX];
int bfs(int n);
int main()
{
    int test, vertices;
    cin>>test;
    while(test--)
    {
        scanf("%d", &vertices);
        memset(flag,0,sizeof(flag));
        for(int i = 0; i < MX; i++)
            adj[i].clear();
        for(int i = 1; i <= vertices; i++)
        {
            int edg;
            cin>>edg;
            for(int j = 0; j < edg; j++)
            {
                int to;
                cin>>to;
                adj[i].push_back(to);
                adj[to].push_back(i);
            }
        }
        int total = 0;
        for(int i = 1; i <= vertices; i++)
        {
            if(flag[i] == 0)
                total += bfs(i);
        }
        cout<<total<<endl;
    }
    return 0;
}

int bfs(int n)
{
    int notbi = 0;
    queue<int> next;
    int one = 1, two = 0;
    next.push(n);
    flag[n] = 1;
    while(!next.empty())
    {
        n = next.front();
        next.pop();
        int siz;
        siz = adj[n].size();
        for(int i = 0; i < siz; i++)
        {
            int j = adj[n][i];
            if(flag[j] == 0)
            {
                next.push(j);
                if(flag[n] == 1)
                {
                    two++;
                    flag[j] = 2;
                }
                else
                {
                    one++;
                    flag[j] = 1;
                }
            }
            else if(flag[j] == flag[n] && j != n)
                    notbi = 1;
        }
    }
    if(notbi == 1) return 0;
    if(one > two)
        return one;
    return two;
}
