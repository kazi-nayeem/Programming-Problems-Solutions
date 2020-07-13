#include<cstdio>

using namespace std;

#define MAX 105

char star[MAX][MAX];

int row, col;
int count;

void bfs(int i, int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, j, k;
    while(scanf("%d %d", &row, &col) == 2)
    {
        if(row == 0 && col == 0) break;
        getchar();
        for(i = 0; i < row; i++)
            gets(star[i]);
        for(i = 0, k = 0; i < row ; i++)
            for(j = 0;j < col; j++)
        {
            if(star[i][j] == '*')
            {
                count = 0;
                bfs(i,j);
                if(count < 2)
                    k++;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}

void bfs(int i, int j)
{
    if(star[i][j] != '*')
        return;
    star[i][j] = '.';
    count ++;
    if(i > 0)
        {
            bfs(i-1, j);
            if(j>0)
                bfs(i-1,j-1);
            if(j+1<col)
                bfs(i -1, j + 1);
        }
    if(i + 1 < row)
    {
        bfs(i+1, j);
        if(j>0)
            bfs(i+1,j-1);
        if(j+1<col)
            bfs(i+1,j+1);
    }
    if(j-1 >= 0)
        bfs(i,j-1);
    if(j+1 < col)
        bfs(i,j+1);
    return;
}




