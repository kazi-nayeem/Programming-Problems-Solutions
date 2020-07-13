#include<cstdio>

using namespace std;

#define MAX 30

char war[MAX][MAX];

int row;

void bfs(int i, int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, j, k, t = 1;
    while(scanf("%d", &row) == 1)
    {
        getchar();
        for(i = 0; i < row; i++)
            gets(war[i]);
        for(i = 0, k = 0; i < row ; i++)
            for(j = 0; j < row; j++)
            {
                if(war[i][j] == '1')
                {
                    k++;
                    bfs(i,j);
                }
            }
        printf("Image number %d contains %d war eagles.\n", t++, k);
    }
    return 0;
}

void bfs(int i, int j)
{
    if(war[i][j] != '1')
        return;
    war[i][j] = '0';
    if(i > 0)
    {
        bfs(i-1, j);
        if(j>0)
            bfs(i-1,j-1);
        if(j+1<row)
            bfs(i -1, j + 1);
    }
    if(i + 1 < row)
    {
        bfs(i+1, j);
        if(j>0)
            bfs(i+1,j-1);
        if(j+1<row)
            bfs(i+1,j+1);
    }
    if(j-1 >= 0)
        bfs(i,j-1);
    if(j+1 < row)
        bfs(i,j+1);
    return;
}

