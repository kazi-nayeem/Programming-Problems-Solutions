#include<cstdio>
using namespace std;

#define MX 21

char maze[MX][MX+2];
int row, colum;
int total;
int x[] = {1,-1,0,0};
int y[] = {0,0,-1,1};

void dfs(int i, int j);

int main()
{
    int time, test, pi, pj;
    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &row, &colum);
        getchar();
        int flag = 1;
        for(int i = 0; i < colum; i++)
        {
            gets(maze[i]);
            if(flag)
            {
                for(int j = 0; j < row; j++)
                {
                    if(maze[i][j] == '@')
                    {
                        pi = i;
                        pj = j;
                        flag = 0;
                        break;
                    }
                }
            }
        }
        total = 0;
        maze[pi][pj] = '.';
        dfs(pi,pj);
        printf("Case %d: %d\n", test, total);
    }
}

void dfs(int i, int j)
{
    if(i < 0 || j < 0 || i >= colum || j >= row) return;
    if(maze[i][j] != '.') return;

    total++;
    maze[i][j] = '@';

    for(int n = 0; n < 4; n++)
        dfs(i+x[n],j+y[n]);
    return;
}
