#include<cstdio>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

#define MX 105

struct data{
        int u, w;
        data(int a, int b)
        {
            u = a;
            w = b;
        }
};

vector <int> adj[MX];

void dijkstra(int arr[], const int str);

int main()
{
    int time, test, node, edge, x, y;
    int arr1[MX], arr2[MX];

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &node, &edge);

        for(int i = 0; i <= node; i++)
        {
            arr1[i] = 0;
            arr2[i] = 0;
            adj[i].clear();
        }
        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        scanf("%d %d", &x, &y);

        dijkstra(arr1,x);
        dijkstra(arr2,y);

        int maxi = 0;
        for(int i = 0; i < node; i++)
        {
            if(arr1[i] + arr2[i] > maxi)
                maxi = arr1[i]+arr2[i];
        }

        printf("Case %d: %d\n", test, maxi);
    }

    return 0;
}

void dijkstra(int arr[], const int str)
{
    int flag[MX] = {0};
    int  n, w, u;
    queue<data> qu;

    qu.push(data(str, 0));
    flag[str] = 1;
    while(!qu.empty())
    {
        n = qu.front().u;
        w = qu.front().w;
        qu.pop();

        int sz = adj[n].size();

        for(int i = 0; i < sz; i++)
        {
            u = adj[n][i];
            if(flag[u] == 1) continue;
            flag[u] = 1;
            arr[u] = w + 1;
            qu.push(data(u,arr[u]));
        }
    }
    return;
}
