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

int flag, take;

void cle(void);
void input(void);
void backtrack(int pos);

int main()
{
    int te , ti;
    scanf("%d", &ti);
    getchar();

    for(te = 1; te <= ti; te++)
    {
        cle();
        input();
        //printf("%d \n", take);
        backtrack(take);

        printf("Case %d:\n", te);
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                putchar('0' + arr[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}

void backtrack(int pos)
{
    if(pos == 81)
    {
        flag = 1;
        return;
    }
    int mx = 100, a = -1, b = -1;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
    {
        if(arr[i][j]> 0) continue;
        int tk = 0;
        for(int k = 1; k < 10; k++)
            if(row[i][k] == 0 && col[j][k] == 0 && grid[i/3][j/3][k] == 0) tk++;
        if(tk == 0) return;
        if(tk < mx)
        {
            a = i;
            b = j;
            mx = tk;
        }
    }
    if(a == -1 || b == -1) return;
    int i = a, j = b;
    for(int k = 1; k < 10; k++)
    {
        if(row[i][k] || col[j][k] || grid[i/3][j/3][k]) continue;
        row[i][k] = 1;
        col[j][k]  = 1;
        grid[i/3][j/3][k] = 1;
        arr[i][j] = k;
        backtrack(pos+1);
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
            take++;
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
    take = flag = 0;
    return;
}

