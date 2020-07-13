#include<stdio.h>
#include<string.h>

#define MX 25

char cont[MX][MX];
int n, row, col;
int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};

void dfs(int i, int j);

int main()
{
    int i, j, maxi;
    while(scanf(" %d %d", &row, &col) == 2)
    {
        getchar();
        for(i = 0; i < row; i++)
            gets(cont[i]);
        scanf("%d %d", &i, &j);
        maxi = 0;
        dfs(i,j);
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
        {
            if(cont[i][j] == 'l')
            {
                n = 0;
                dfs(i,j);
                maxi = (maxi>n) ? maxi : n;
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}

void dfs(int i, int j)
{
    if(i >= row ||  i < 0) return;
    j = (j+col) % col;
    if(cont[i][j] != 'l') return;

    cont[i][j] = 'w';
    n++;
    int k;
    for( k = 0; k < 4; k++)
    {
        dfs(i+x[k], j+y[k]);
    }
    return;
}
