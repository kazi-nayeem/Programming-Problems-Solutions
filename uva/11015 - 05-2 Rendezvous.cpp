#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define INF 25000

int dis[23][23];

void cle(int node);
int floyd(int node);

int main()
{
    int node, edge, s, e, w, te = 1;
    char name[22][12];
    while(scanf("%d %d", &node, &edge) == 2)
    {
        if(node == 0 && edge == 0) return 0;
        cle(node);
        getchar();
        for(int i = 0; i < node; i++) gets(name[i]);

        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d %d", &s, &e, &w);
            if(dis[s][e] > w)
                dis[s][e] = w;
            if(dis[e][s] > w)
                dis[e][s] = w;
        }
        printf("Case #%d : %s\n", te++, name[floyd(node)]);
    }
    return 0;
}

int floyd(int node)
{
    for(int k = 1; k <= node; k++)
        for(int i = 1; i <= node; i++)
            for(int j = 1; j <= node; j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    int maxi = INF, no = 0;
    for(int i = 1; i <= node; i++)
    {
        int total=0;
        for(int j = 1; j <= node; j++)
            total += dis[i][j];
        if(maxi > total)
            maxi = total, no = i;
    }
    return (no - 1);
}

void cle(int node)
{
    for(int i = 1; i <= node; i++)
        for(int j = 1; j <= node; j++)
        dis[i][j] = (i == j)? 0:INF;
    return;
}
