#include<cstdio>

using namespace std;

#define MAX 103

char battle[MAX][MAX];

int row;

void dfs(int i, int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, j, k;
    int test, t = 1;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &row);
        getchar();
        for(i = 0; i < row; i++)
            gets(battle[i]);
        for(i = 0, k = 0; i < row ; i++)
            for(j = 0; j < row; j++)
            {
                if(battle[i][j] == 'x')
                {
                    k++;
                    dfs(i,j);
                }
            }
        printf("Case %d: %d\n", t++, k);
    }
    return 0;
}

void dfs(int i, int j)
{
    if(battle[i][j] != 'x' && battle[i][j] != '@')
        return;
    battle[i][j] = '.';
    if(i > 0)
    {
        dfs(i-1, j);
        if(j>0)
            dfs(i-1,j-1);
        if(j+1<row)
            dfs(i -1, j + 1);
    }
    if(i + 1 < row)
    {
        dfs(i+1, j);
        if(j>0)
            dfs(i+1,j-1);
        if(j+1<row)
            dfs(i+1,j+1);
    }
    if(j-1 >= 0)
        dfs(i,j-1);
    if(j+1 < row)
        dfs(i,j+1);
    return;
}


