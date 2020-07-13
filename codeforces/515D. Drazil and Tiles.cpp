#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long
#define MX 2050

int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

int deg[MX][MX];
char str[MX][MX];
char take[MX][MX];
int row, col;

bool func(void)
{
    queue<int> qu;
    for(int i= 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(str[i][j] == '*') continue;
            if(deg[i][j] == 4) return true;
            if(deg[i][j] == 3)
            {
                qu.push(i);
                qu.push(j);
                deg[i][j] = 100;
            }
        }
    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        int y = qu.front();
        qu.pop();
        if(take[x][y] == 1 || str[x][y] != '.') continue;
        take[x][y] = 1;
        //printf("%d %d\n", x, y);
        for(int k = 0; k < 4; k++)
        {
            int tx = x+xx[k];
            int ty = y+yy[k];
            if(tx < 0 || ty < 0 || tx >= row || ty >= col || take[tx][ty] == 1 || str[tx][ty] != '.') continue;
            take[tx][ty] = 1;
            if(k == 1)
            {
                str[tx][ty] = '<';
                str[x][y] = '>';
            }
            else if(k == 0)
            {
                str[tx][ty] = '>';
                str[x][y] = '<';
            }
            else if(k == 2)
            {
                str[tx][ty] = 'v';
                str[x][y] = '^';
            }
            else if(k == 3)
            {
                str[tx][ty] = '^';
                str[x][y] = 'v';
            }

            for(int i = 0; i < 4; i++)
            {
                int ttx = tx+xx[i];
                int tty = ty+yy[i];
                if(ttx < 0 || tty < 0 || ttx >= row || tty >= col || take[ttx][tty] == 1|| str[ttx][tty] != '.') continue;
                deg[ttx][tty]++;
                if(deg[ttx][tty] == 3 && take[ttx][tty] == 0)
                {
                    qu.push(ttx);
                    qu.push(tty);
                    deg[ttx][tty] = 100;
                }
            }
            break;
        }
    }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        if(str[i][j] == '.') return true;
    return false;
}

void pro(void)
{
    int tx, ty;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(str[i][j] == '.') continue;
            for(int k = 0; k < 4; k++)
            {
                tx = i+xx[k];
                ty = j+yy[k];
                if(tx < 0 || ty < 0 || tx >= row || ty >= col) continue;
                deg[tx][ty]++;
            }
        }
    for(int i = 0; i < row; i++)
        deg[i][0]++, deg[i][col-1]++;
    for(int i = 0; i < col; i++)
        deg[0][i]++, deg[row-1][i]++;
}

int main()
{
    scanf("%d%d", &row, &col);
    for(int i = 0; i < row; i++)
        scanf(" %s", str[i]);
    pro();
    if(func()) puts("Not unique");
    else
    {
        for(int i = 0; i < row; i++)
            puts(str[i]);
    }
    return 0;
}

