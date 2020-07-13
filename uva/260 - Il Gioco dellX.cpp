#include<cstdio>

using namespace std;

#define MAX 205

char gioco[MAX][MAX];

int row;
int count;

void bfs(int i, int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, k = 1;
    while(scanf("%d", &row) == 1)
    {
        if(row == 0) break;
        getchar();
        for(i = 0; i < row; i++)
            gets(gioco[i]);
        for(i = 0; i < row ; i++)
        {
            if(gioco[i][0] == 'w')
            {
                count = 0;
                bfs(i,0);
                if(count  == 1)
                    break;
            }
        }
        if(count == 1)
            printf("%d W\n", k++);
        else
            printf("%d B\n", k++);
    }
    return 0;
}

void bfs(int i, int j)
{
    if(count == 1) return;
    if(gioco[i][j] != 'w')
        return;
    if(j == row - 1 && gioco[i][j] == 'w')
    {
        count = 1;
        return;
    }
    gioco[i][j] = 'b';
    if(i > 0)
        {
            bfs(i-1, j);
            if(j>0)
                bfs(i-1,j-1);
        }
    if(i + 1 < row)
    {
        bfs(i+1, j);
        if(j+1<row)
            bfs(i+1,j+1);
    }
    if(j-1 >= 0)
        bfs(i,j-1);
    if(j+1 < row)
        bfs(i,j+1);
    return;
}



