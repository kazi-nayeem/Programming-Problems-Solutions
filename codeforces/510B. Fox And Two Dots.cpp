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

int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

int row, col;
int flag[55][55];
int vis[55][55];
char str[55][55], now;

bool dfs(int ni,int nj,int pi,int pj)
{
    if(ni < 0 || nj < 0 || ni >= row || nj >= col) return false;
    if(str[ni][nj] != now) return false;
    if(vis[ni][nj] == 1) return true;
    vis[ni][nj] = 1;
    for(int i = 0; i < 4; i++)
    {
        if((pi == ni+xx[i]) && (pj == nj+yy[i])) continue;
        if(dfs(ni+xx[i],nj+yy[i],ni,nj)) return true;
    }
    vis[ni][nj] = 0;
    return false;
}

void dfs(int ni,int nj)
{
    if(ni < 0 || nj < 0 || ni >= row || nj >= col) return;
    if(str[ni][nj] != now) return;
    if(flag[ni][nj] == 1) return;
    flag[ni][nj] = 1;
    for(int i = 0; i < 4; i++)
    {
        dfs(ni+xx[i],nj+yy[i]);
    }
    return ;
}

bool func()
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(flag[i][j] == 1) continue;
            memset(vis,0,sizeof vis);
            now = str[i][j];
            if(dfs(i, j, i, j)) return true;
            dfs(i,j);
        }
    return false;
}

int main()
{
    scanf("%d%d", &row, &col);
    for(int i = 0; i < row; i++)
        scanf(" %s", str[i]);
    if(func()) puts("Yes");
    else puts("No");
    return 0;
}

