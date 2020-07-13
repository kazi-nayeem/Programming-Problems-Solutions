#include<cstdio>
#include<cstring>
using namespace std;

int x[] = {0,0,-1,1};
int y[] = {-1,1,0,0};

char str[502][505];
int total[502][502], row, colum;

int func(int pox, int poy);
int dfs(int i,int j);
void dfsin(int i, int j, int t);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti, maze, qu , px, py;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &row, &colum, &qu);
        gets(str[0]);
        for(int i = 0; i < row; i++)
            gets(str[i]);

        memset(total,-1,sizeof total);

        printf("Case %d:\n", te);

        for(int i = 0; i < qu; i++)
        {
            scanf("%d%d", &px, &py);
            maze = func(px-1,py-1);
            printf("%d\n", maze);
        }
    }
    return 0;
}

int func(int pox, int poy)
{
    if(total[pox][poy] != -1) return total[pox][poy];
    int k = dfs(pox,poy);
    //printf("%d", k);
    dfsin(pox,poy,k);
    return k;
}
int dfs(int i,int j)
{
    if(i < 0 || j < 0 || i >= row || j >= colum) return 0;
    if(str[i][j] != '.' && str[i][j] != 'C') return 0;
    int total = 0;
    if(str[i][j] == 'C') total++;
    str[i][j] = 'V';
    for(int k = 0; k < 4; k++)
        total += dfs(i+x[k],j+y[k]);
    return total;
}
void dfsin(int i, int j, int t)
{
    if(i < 0 || j < 0 || i >= row || j >= colum) return;
    if(str[i][j] != 'V') return;
    str[i][j] = 'P';
    total[i][j] = t;
    for(int k = 0; k < 4; k++)
        dfsin(i+x[k],j+y[k], t);
    return;
}
