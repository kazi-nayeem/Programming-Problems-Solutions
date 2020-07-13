#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

int arr[9][10];
int row[9][10];
int col[9][10];
int grid[3][3][10];

int flag;

void cle(void);
void input(void);
void backtrack(int i,int j);

int main()
{
    int te , ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        cle();
        input();
        backtrack(0,0);

        printf("Case %d:\n", te);
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                printf("%d", arr[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}

void backtrack(int i,int j)
{
    if((i+1 == 9) && j == 9)
    {
        flag = 1;
        return;
    }
    if(j == 9) i++, j = 0;
    if(arr[i][j])
    {
        backtrack(i, j+1);
        return;
    }
    for(int k = 1; k < 10; k++)
    {
        if(row[i][k] || col[j][k] || grid[i/3][j/3][k]) continue;
        row[i][k] = 1;
        col[j][k]  = 1;
        grid[i/3][j/3][k] = 1;
        arr[i][j] = k;
        backtrack(i,j+1);
        if(flag) return;
        row[i][k] = 0;
        col[j][k]  = 0;
        grid[i/3][j/3][k] = 0;
        arr[i][j] = 0;
    }
    return;
}

void input(void)
{
    int a;
    char ch;
    getchar();
    for(int i = 0; i < 9; i++)
    {
        getchar();
        for(int j = 0; j < 9; j++)
        {
            ch = getchar();
            if(ch == '.') continue;
            a = (int)ch - '0';
            arr[i][j] = a;
            row[i][a] = 1;
            col[j][a] = 1;
            grid[i/3][j/3][a] = 1;
        }
    }
    return;
}

void cle(void)
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 10; j++)
    {
        arr[i][j] = 0;
        row[i][j] = 0;
        col[i][j] = 0;
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 10; k++)
                grid[i][j][k] = 0;
    flag = 0;
    return;
}

