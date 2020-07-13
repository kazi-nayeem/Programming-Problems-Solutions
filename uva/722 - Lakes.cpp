#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void dfs(int i, int j);
char lake[102][102];
int total;
int colum[102];
int row;
int main()
{
    freopen("input.txt", "r",stdin);
    int time;
    scanf("%d", &time);
    getchar();
    getchar();
    while(time--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        getchar();
        int i = 0;
        memset(colum,0,sizeof colum);
        while(gets(lake[i]))
        {
            colum[i] = strlen(lake[i]);
            if(colum[i] == 0) break;
            i++;
        }
        row = i;
        total = 0;
        dfs(x-1,y-1);
        printf("%d\n", total);
        if(time)
            putchar('\n');
    }
    return 0;
}

void dfs(int i, int j)
{
    if(i < 0 || j < 0 || i>=row)
        return;
    if(j>=colum[i])
        return;
    if(lake[i][j] != '0')
        return;
    total++;
    lake[i][j] = '1';
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    return;
}
