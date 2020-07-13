#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;

#define inf 1000000

int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

struct data
{
    int x, y, dis;
    data() {}
    data(int a, int b, int c)
    {
        x = a;
        y = b;
        dis = c;
    }
};

int row;
char flag[12][12];
char str[12][12];
int res[3][3];

void bfs(int nx, int ny, int p)
{
    memset(flag,-1, sizeof flag);
    queue<data> qu;
    qu.push(data(nx,ny,0));
    flag[nx][ny] = 1;
    int x, y, ds, tx, ty;
    while(!qu.empty())
    {
        x = qu.front().x;
        y = qu.front().y;
        ds = qu.front().dis;
        qu.pop();

        if(str[x][y] != '.' && str[x][y] != '#')
            res[p][str[x][y]-'A'] = ds;
        for(int i = 0; i < 4; i++)
        {
            tx = x+xx[i];
            ty = y+yy[i];
            if(tx < 0 || tx >= row || ty < 0 || ty >= row || str[tx][ty] == '#' || flag[tx][ty] != -1) continue;
            qu.push(data(tx,ty,ds+1));
            flag[tx][ty] = 1;
        }
    }
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &row);
        for(int i = 0; i < row; i++)
            scanf(" %s", str[i]);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                res[i][j] = inf;
        int pos = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < row; j++)
                if(str[i][j] == 'X')
                    bfs(i,j,pos++);
        int ans = inf;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == j) continue;
                for(int k = 0; k < 3; k++)
                {
                    if(k == i || k == j) continue;
                    ans = min(ans,max(res[1][i], max(res[2][j],res[3][k])));
                }
            }
        }
        if(ans == inf)
            printf("Case %d: trapped\n", te);
        else
            printf("Case %d: %d\n", te, ans);
    }
    return 0;
}
