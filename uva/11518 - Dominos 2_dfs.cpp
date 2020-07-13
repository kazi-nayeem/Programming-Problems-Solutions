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
int down;

void bfs(int n);

int main()
{
    //freopen("input.txt", "r", stdin);
    int time;
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

        for(int i = 0; i < test; i++)
        {
            scanf("%d", &x);
            down = 0;
            bfs(x);
            printf("%d\n", down);
        }
    }
    return 0;
}

void bfs(int n)
{
    if(flag[n]) return;
    flag[n] = 1;
    down++;
    int sz = (int) dominos[n].size();
    for(int i = 0; i < sz; i++)
    {
        bfs(dominos[n][i]);
    }
    return;
}
