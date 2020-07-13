#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 1005
vector<int> fact[MAX];
bool visit[MAX];

typedef struct st
{
    int num, dist;
} pairof;


void sieve(void)
{
    int i, j;

    for(i = 4; i < MAX; i += 2)
        fact[i].push_back(2);

    for(i = 3; i < MAX; i += 2)
    {
        if(fact[i].empty())
        {
            for(j = i + i; j < MAX; j += i)
                fact[j].push_back(i);
        }
    }
}


int bfs(int n, int m)
{
    memset(visit, 0, sizeof(visit));

    queue<pairof> next;
    pairof temp;
    temp.num = n;
    temp.dist = 0;
    next.push(temp);

    int dis, sz, j;
    while(next.size())
    {
        temp = next.front();
        next.pop();

        n = temp.num;
        dis = temp.dist;
        visit[n] = true;

        if(n == m) return dis;
        sz = fact[n].size();

        for(int i = 0; i < sz; i++)
        {
            j = n + fact[n][i];
            if(!visit[j])
            {
                if(j < m)
                {
                    temp.num = j;
                    temp.dist = dis + 1;
                    next.push(temp);
                }
                else if(j == m)
                    return dis + 1;
            }
        }
    }

    return -1;
}

int main()
{
    sieve();

    int time, test;
    int n, m;

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &n, &m);
        printf("Case %d: %d\n", test, bfs(n, m));
    }

    return 0;
}



