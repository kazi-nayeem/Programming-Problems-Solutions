#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define MAX 1005
#define pd push_back
using namespace std;

map<string,int> nodes;
vector<int> adj[MAX];

string name[MAX];
bool flag[MAX];
int parent[MAX];
int start, finish;

int bfs(void);
void path(int p);

int main()
{
    int edgs;
    int mapc = 0;
    int i, j;
    bool newline = false;
    string str1, str2;
    while(scanf("%d", &edgs) == 1)
    {
        if(newline == true)
            putchar('\n');
        newline == true;
        for(i = 0; i < MAX; i++)
            adj[i].clear();
        mapc = 1;
        nodes.clear();
        memset(flag,0,sizeof(flag));
        memset(parent,0,sizeof(parent));
        for(i = 0; i < edgs; i++)
        {
            cin>>str1>>str2;
            if(nodes.find(string(str1)) == nodes.end())
            {
                nodes[string(str1)] = mapc;
                name[mapc++] = string(str1);
            }
            if(nodes.find(string(str2)) == nodes.end())
            {
                nodes[string(str2)] = mapc;
                name[mapc++] = string(str2);
            }
            adj[nodes[string(str1)]].pd(nodes[string(str2)]);
            adj[nodes[str2]].pd(nodes[str1]);
        }
        cin>>str1>>str2;
        if(nodes.find(string(str1)) == nodes.end())
        {
            nodes[string(str1)] = mapc;
            name[mapc++] = string(str1);
        }
        if(nodes.find(string(str2)) == nodes.end())
        {
            nodes[string(str2)] = mapc;
            name[mapc++] = string(str2);
        }
        start = nodes[string(str1)];
        finish = nodes[string(str2)];
        j = bfs();
        if(start == finish)
            cout<<name[start]<<" "<<name[finish]<<endl;
        else if(j == -1)
            printf("No route\n");
        else
            path(finish);
    }
    return 0;
}

int bfs(void)
{
    queue<int > next;
    int n, i, j;
    int siz;
    next.push(start);
    flag[start] = true;
    while(!next.empty())
    {
        n = next.front();
        next.pop();
        siz = adj[n].size();
        for(i = 0; i < siz; i++)
        {
            j = adj[n][i];
            if(flag[j] == false)
            {
                flag[j] = true;
                parent[j] = n;
                if(j == finish)
                    return 1;
                next.push(j);
            }
        }
    }
    return -1;
}
void path(int p)
{
    if(parent[p] == start)
    {
        cout<<name[parent[p]]<<" "<<name[p]<<endl;
        return;
    }
    path(parent[p]);
    cout<<name[parent[p]]<<" "<<name[p]<<endl;
    return;
}

