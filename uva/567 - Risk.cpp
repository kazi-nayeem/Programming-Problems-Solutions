#include<cstdio>
#include<iostream>
using namespace std;

#define INF 50000
#define MX 105

int graph[MX][MX];

void floyd(int n);
void cle(void);

int main()
{
    int n, a, b, te = 1;
    while(scanf("%d", &n) == 1)
    {
        int maxi = 1;
        cle();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            graph[a][1] = 1;
            graph[1][a] = 1;
            maxi = (maxi < a)? a : maxi;
        }
        for(int i = 2; i < 20; i++)
        {
            scanf("%d", &n);
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &a);
                graph[a][i] = 1;
                graph[i][a] = 1;
                maxi = (maxi < a)? a : maxi;
            }
        }
        floyd(maxi);
        printf("Test Set #%d\n", te++);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            printf("%2d to %2d: %d\n", a, b, graph[a][b]);
        }
        puts("");
    }
    return 0;
}

void floyd(int n)
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    return;
}

void cle(void)
{
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            graph[i][j] = (i == j)? 0:INF;
    return;
}
