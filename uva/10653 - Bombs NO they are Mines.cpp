#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;

#define MAX 1005

typedef struct st{int i, j, dis;} pai;

char bombs[MAX][MAX];
int row, colum;

int bfs(pai start, pai finish);

int main()
{
    while(scanf("%d %d", &row, &colum) == 2)
    {
        if(row == 0 && colum == 0) return 0;

        memset(bombs, 'e', sizeof bombs);

        int bomrow;
        scanf("%d", &bomrow);

        for(int i = 0; i < bomrow; i++)
        {
            int tbomb, rownum, pos;

            scanf("%d %d", &rownum, &tbomb);

            for(int j = 0; j < tbomb; j++)
            {
                scanf("%d", &pos);
                bombs[rownum][pos] = 'b';
            }
        }

        pai str, en;
        scanf("%d %d %d %d", &str.i, &str.j, &en.i, &en.j);

        printf("%d\n", bfs(str,en));
    }
    return 0;
}

int bfs(pai start, pai finish)
{
    queue<pai> next;
    pai temp;
    int i, j, dis;

    temp.i = start.i;
    temp.j = start.j;
    temp.dis = 0;
    bombs[start.i][start.j] = 'b';

    next.push(temp);

    while(next.size())
    {
        temp = next.front();
        next.pop();

        i = temp.i;
        j = temp.j;
        dis = temp.dis;

        if(i>0)
        {
            if(i-1 == finish.i && j == finish.j)
                return dis + 1;
            if(bombs[i-1][j] == 'e')
            {
                temp.i = i-1;
                temp.j = j;
                temp.dis = dis+1;

                next.push(temp);

                bombs[i-1][j] = 'b';
            }
        }

        if(i+1<row)
        {
            if(i+1 == finish.i && j == finish.j)
                return dis + 1;
            if(bombs[i+1][j] == 'e')
            {
                temp.i = i+1;
                temp.j = j;
                temp.dis = dis+1;

                next.push(temp);

                bombs[i+1][j] = 'b';
            }
        }

        if(j>0)
        {
            if(i == finish.i && j-1 == finish.j)
                return dis + 1;
            if(bombs[i][j-1] == 'e')
            {
                temp.i = i;
                temp.j = j-1;
                temp.dis = dis+1;

                next.push(temp);

                bombs[i][j-1] = 'b';
            }
        }

        if(j+1<colum)
        {
            if(i == finish.i && j+1 == finish.j)
                return dis + 1;
            if(bombs[i][j+1] == 'e')
            {
                temp.i = i;
                temp.j = j+1;
                temp.dis = dis+1;

                next.push(temp);

                bombs[i][j+1] = 'b';
            }
        }
    }
    return 0;
}
