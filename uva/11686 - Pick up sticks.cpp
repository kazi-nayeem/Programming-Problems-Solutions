#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

#define MX 1000005

vector<int> order;
vector<int> co[MX];
int indegree[MX];

void sortorder(int work);

int main()
{
    int work, connect, sz;
    while(scanf("%d %d", &work, &connect) == 2)
    {
        if(work == 0 && connect == 0) return 0;
        for(int i= 0; i <= work; i++)
            co[i].clear();
        memset(indegree, 0, sizeof indegree);

        int x, y;
        for(int i=0; i < connect; i++)
        {
            scanf("%d %d", &x, &y);
            co[x].push_back(y);
            indegree[y]++;
        }

        sortorder(work);

        sz = order.size();
        if(sz == work)
        {
            for(int i = 0; i < sz; i++)
                printf("%d\n", order[i]);
        }
        else
            printf("IMPOSSIBLE\n");

    }
    return 0;
}

void sortorder(int work)
{
    queue<int> next;
    order.clear();
    int n, sz;
    for(int i = 1; i <= work; i++)
    {
        if(indegree[i] == 0)
        {
            next.push(i);
            order.push_back(i);
        }
    }

    while(!next.empty())
    {
        n = next.front();
        next.pop();

        sz = co[n].size();

        for(int i = 0; i < sz; i++)
        {
            if(indegree[co[n][i]] == 1)
            {
                order.push_back(co[n][i]);
                next.push(co[n][i]);
            }
            else
                indegree[co[n][i]]--;
        }
    }
    return;
}


