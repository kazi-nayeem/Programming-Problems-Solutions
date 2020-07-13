#include<cstdio>
#include<cstring>
#include<string>

char grid[31][85];
int flag[31][85];
int len[31];
int colum;
char wall;
char c;
void colour(int i, int j);

int main()
{
    int i, j, k = 0;
    while(gets(grid[0]))
    {
        if(k == 1)
        {
            gets(grid[0]);
            putchar('\n');
        }
        k = 1;
        memset(flag,0,sizeof(flag));
        len[0] = strlen(grid[0]);
        if(len[0] == 0) break;
        colum = 1;
        while(gets(grid[colum]))
        {
            if(grid[colum][0] == '_') break;
            len[colum] = strlen(grid[colum]);
            colum++;
        }
        wall = '\0';
        for(i = 0; i < colum; i++)
        {
            if(wall == '\0')
            {
                for(j = 0; j < len[i]; j++)
                    if(grid[i][j] != ' ')
                    {
                        wall = grid[i][j];
                        break;
                    }
            }
        }
        for(i = 0; i < colum; i++)
            for(j = 0; j < len[i]; j++){
                if(grid[i][j] != ' ' && grid[i][j] != wall)
                {
                    c = grid[i][j];
                    colour(i,j);
                }
        }
        for(i= 0; i <= colum; i++)
            puts(grid[i]);
    }
    return 0;
}

void colour(int i, int j)
{
    if(i < 0 || j < 0 || i >= colum || j >= len[i])
        return;
    if(grid[i][j] == wall)
        return;
    if(flag[i][j] == 1)
        return;
    flag[i][j] = 1;
    grid[i][j] = c;
    colour(i-1,j);
    colour(i+1,j);
    colour(i,j-1);
    colour(i,j+1);
    return;
}
