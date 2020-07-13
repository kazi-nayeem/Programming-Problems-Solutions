#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

#define MX 10005

int flag[MX];
vector<int> dominos[MX];

int bfs(int n);

int main()
{
    //freopen("input.txt", "r", stdin);
    int time, total;
    int card, connect, test;
    int x, y;
    scanf("%d", &time);

    while(time--)
    {
        scanf("%d %d %d", &card, &connect, &test);

        for(int i = 0; i <= card; i++) dominos[i].clear();
        memset(flag, 0, sizeof flag);

        for(int i = 0; i < connect; i++)
        {
            scanf("%d %d", &x, &y);
            dominos[x].push_back(y);
        }
        total = 0;
        for(int i = 0; i < test; i++)
        {
            scanf("%d", &x);
            total += bfs(x);
        }
        printf("%d\n", total);
    }
    return 0;
}

int bfs(int n)
{
    int total = 0, i, k;
    queue<int> next;

    next.push(n);
    flag[n] = 1;
    while(!next.empty())
    {
        n = next.front();
        next.pop();

        total++;

        int sz = (int) dominos[n].size();
        for(i = 0; i < sz; i++)
        {
            k = dominos[n][i];
            if(flag[k] == 0)
            {
                flag[k] = 1;
                next.push(k);
            }
        }
    }
    return total;
}
