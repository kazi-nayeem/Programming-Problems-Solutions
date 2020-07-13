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

int n, total, flag;

void cle(void);
void input(void);
void backtrack(int i,int j);

int main()
{
    int te = 0;
    while(scanf("%d", &n) == 1)
    {
        if(te) putchar('\n');
        te = 1;
        total = n * n;
        cle();
        input();
        if(flag)
        {
            printf("NO SOLUTION\n");
            continue;
        }
        flag = 0;
        backtrack(0,0);
        if(flag == 0)
        {
            printf("NO SOLUTION\n");
            continue;
        }
        for(int i = 0; i < total; i++)
        {
            for(int j = 1; j < total; j++)
            {
                if(j) putchar(' ');
                printf("%d", arr[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}

void backtrack(int i,int j)
{
    if((i+1 == total) && j == total)
    {
        flag = 1;
        return;
    }
    if(j == total) i++, j = 0;
    if(arr[i][j])
    {
        backtrack(i, j+1);
        return;
    }
    for(int k = 1; k < 10; k++)
    {
        if(row[i][k] || col[j][k] || grid[i/n][j/n][k]) continue;
        row[i][k] = 1;
        col[j][k]  = 1;
        grid[i/n][j/n][k] = 1;
        arr[i][j] = k;
        backtrack(i,j+1);
        if(flag) return;
        row[i][k] = 0;
        col[j][k]  = 0;
        grid[i/n][j/n][k] = 0;
        arr[i][j] = 0;
    }
    return;
}

void input(void)
{
    int a;
    for(int i = 0; i < total; i++)
        for(int j = 0; j < total; j++)
        {
            scanf("%d", &a);
            if(flag) continue;
            if(a == 0) continue;
            if(row[i][a] || col[j][a] || grid[i/n][j/n][a])
            {
                flag = 1;
                continue;
            }
            arr[i][j] = a;
            row[i][a] = 1;
            col[j][a] = 1;
            grid[i/n][j/n][a] = 1;
        }
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
