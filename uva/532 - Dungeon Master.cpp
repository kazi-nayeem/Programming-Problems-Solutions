#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

#define MX 35

struct posi{int i, j, k, dis;};

int level, row, colum;
char maze[MX][MX][MX];

int bfs(posi start);

int main()
{
    posi start;
    while(scanf(" %d %d %d", &level, &row, &colum) == 3)
    {
        if(level == 0 && row == 0 && colum == 0) return 0;
        start.dis = 0;

        for(int i = 0; i < level; i++)
        {
            getchar();

            for(int j = 0; j < row; j++)
            {
                    gets(maze[i][j]);

                    if(start.dis == 0)
                    {
                        for(int k = 0; k < colum; k++)
                            if(maze[i][j][k] == 'S')
                            {
                                start.i = i;
                                start.j = j;
                                start.k = k;
                                start.dis = 1;
                            }
                    }
            }
        }
        int total = bfs(start);
        if(total == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", total);
    }
    return 0;
}

int bfs(posi start)
{
    queue<posi> next;
    int i, j, k, dis;

    start.dis = 0;
    next.push(start);
    while(next.size())
    {
        i = next.front().i;
        j = next.front().j;
        k = next.front().k;
        dis = next.front().dis;

        next.pop();
        if(i>0)
        {
            if(maze[i-1][j][k] == 'E') return dis+1;

            if(maze[i-1][j][k] == '.')
            {
                start.i = i-1;
                start.j = j;
                start.k = k;
                start.dis = dis+1;

                next.push(start);
                maze[i-1][j][k] = 'b';
            }
        }
        if(j>0)
        {
            if(maze[i][j-1][k] == 'E') return dis+1;

            if(maze[i][j-1][k] == '.')
            {
                start.i = i;
                start.j = j-1;
                start.k = k;
                start.dis = dis+1;

                next.push(start);
                maze[i][j-1][k] = 'b';
            }
        }
        if(k>0)
        {
            if(maze[i][j][k-1] == 'E') return dis+1;

            if(maze[i][j][k-1] == '.')
            {
                start.i = i;
                start.j = j;
                start.k = k-1;
                start.dis = dis+1;

                next.push(start);
                maze[i][j][k-1] = 'b';
            }
        }
        if(i+1<level)
        {
            if(maze[i+1][j][k] == 'E') return dis+1;

            if(maze[i+1][j][k] == '.')
            {
                start.i = i+1;
                start.j = j;
                start.k = k;
                start.dis = dis+1;

                next.push(start);
                maze[i+1][j][k] = 'b';
            }
        }
        if(j+1<row)
        {
            if(maze[i][j+1][k] == 'E') return dis+1;

            if(maze[i][j+1][k] == '.')
            {
                start.i = i;
                start.j = j+1;
                start.k = k;
                start.dis = dis+1;

                next.push(start);
                maze[i][j+1][k] = 'b';
            }
        }
        if(k+1<colum)
        {
            if(maze[i][j][k+1] == 'E') return dis+1;

            if(maze[i][j][k+1] == '.')
            {
                start.i = i;
                start.j = j;
                start.k = k+1;
                start.dis = dis+1;

                next.push(start);
                maze[i][j][k+1] = 'b';
            }
        }
    }
    return -1;
}
