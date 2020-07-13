#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 28

char blob[MAX][MAX];

int row, col;
int count;

void dfs(int i, int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, j, k, n, len, f = 0;
    scanf("%d", &n);
    getchar();
    getchar();
    while(n--)
    {
        if(f) putchar('\n');
        f = 1;
        for(i = 0, len = 1; len != 0;len = strlen(blob[i++]))
                gets(blob[i]);
        row = i - 1;
        col = strlen(blob[0]);
        //for(i = 0; i < row; i++)
          //  puts(blob[i]);
        for(i = 0, k = 0; i < row ; i++)
            for(j = 0;j < col; j++)
        {
            if(blob[i][j] == '1')
            {
                count = 0;
                dfs(i,j);
                if(k < count)
                    k = count;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}

void dfs(int i, int j)
{
    if(blob[i][j] != '1')
        return;
    blob[i][j] = '0';
    count++;
    if(i > 0)
        {
            dfs(i-1, j);
            if(j>0)
                dfs(i-1,j-1);
            if(j+1<col)
                dfs(i -1, j + 1);
        }
    if(i + 1 < row)
    {
        dfs(i+1, j);
        if(j>0)
            dfs(i+1,j-1);
        if(j+1<col)
            dfs(i+1,j+1);
    }
    if(j-1 >= 0)
        dfs(i,j-1);
    if(j+1 < col)
        dfs(i,j+1);
    return;
}

