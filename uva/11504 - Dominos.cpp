#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

#define MX 100005

bool flag[MX];
vector<int> dominos[MX];
vector<int> backwa[MX];

void dfs(int n);
int bcdfs(int n);

int main()
{
    int tim, total;
    int card, connect;
    int x, y;
    scanf("%d", &tim);

    while(tim--)
    {
        scanf("%d %d", &card, &connect);

        for(int i = 0; i <= card; i++)
        {
            flag[i] = false;
            dominos[i].clear();
            backwa[i].clear();
        }
        total = 0;

        for(int i = 0; i < connect; i++)
        {
            scanf("%d %d", &x, &y);
            dominos[x].push_back(y);
            backwa[y].push_back(x);
        }

        for(int i = 1; i <= card; i++)
        {
            if(flag[i] == false)
            {
                flag[i] = true;
                dfs(i);
                int tem = bcdfs(i);
                total += (tem)? tem:1;
                //printf("%d  %d\n", i, tem);
            }
        }
        printf("%d\n", total);
    }
    return 0;
}

void dfs(int n)
{
    int sz = (int) dominos[n].size();
    int k;
    for(int i = 0; i < sz; i++)
    {
        k = dominos[n][i];
        if(flag[k] == false)
        {
            flag[k] = true;
            dfs(k);
        }
    }
    return;
}

int bcdfs(int n)
{
    if(backwa[n].size() == 0) {
            flag[n] = true;
            return 1;
    }
    //printf("%d\n", n);
    int sz = (int) backwa[n].size();
    int k, tot = 0;
    for(int i = 0; i < sz; i++)
    {
        k = backwa[n][i];
        if(flag[k] == false)
        {
            flag[k] = true;
            tot+=bcdfs(k);
        }
    }
    return tot;
}
