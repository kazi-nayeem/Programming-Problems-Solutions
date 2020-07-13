#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MX 25

typedef struct dt{char ch;
    int total;
} typ;

char cont[MX][MX];
int n, row, col;
int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};
char ch;

int comp(const void *a, const void *b);
void dfs(int i, int j);

int main()
{
    typ arr[26];
    int i, j, maxi, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %d %d", &row, &col);
        getchar();
        for(i = 0; i < row; i++)
            gets(cont[i]);
        for(i = 0; i < 26; i++)
        {
            arr[i].total = 0;
            arr[i].ch = 'a'+i;
        }
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
        {
            if(cont[i][j] != '\0')
            {
                n = 0;
                ch = cont[i][j];
                dfs(i,j);
                arr[ch-'a'].total++;
            }
        }

        qsort(arr, 26, sizeof(typ), comp);

        printf("World #%d\n", te);
        for(i = 0; i < 26; i++)
        {
            if(arr[i].total == 0) break;
            printf("%c: %d\n", arr[i].ch, arr[i].total);
        }

    }
    return 0;
}

void dfs(int i, int j)
{
    if(i >= row ||  i < 0 || j >= col || j < 0) return;
    if(cont[i][j] != ch) return;

    cont[i][j] = '\0';
    n++;
    int k;
    for( k = 0; k < 4; k++)
    {
        dfs(i+x[k], j+y[k]);
    }
    return;
}

int comp(const void *a, const void *b)
{
    typ  temp1 = *(typ *) a;
    typ temp2 = *(typ *) b;
    if(temp1.total != temp2.total) return temp2.total - temp1.total;
    return (int) temp1.ch - temp2.ch;
}
