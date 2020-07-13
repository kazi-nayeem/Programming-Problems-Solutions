#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

#define MX 60
#define inf 650

int xx[] = {0,0,-1,1};
int yy[] = {-1,1,0,0};

char str[30][30];
int dis[60][60];
int no_human[30][30];
int vis[30][30];
int human;
int row, col;

vector<int> adj[MX];
int flag[MX];
int match[MX];
int te, ti, n, now;

bool Bipartite_Match(int n)
{
    int v;
    int sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(flag[v] == now) continue;
        flag[v] = now;
        if(match[v] == -1 || Bipartite_Match(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}

void graph_cls(void)
{
    for(int i = 0; i <= n; i++) adj[i].clear();
    memset(match,-1,sizeof match);
}

void input(int mxdis)
{
    graph_cls();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < human; j++)
        {
            if(dis[i][j] != -1 && dis[i][j] <= mxdis)
                adj[i].push_back(j);
        }
}

bool bpm(int mxdis)
{
    input(mxdis);
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        now++;
        if(Bipartite_Match(i)) total++;
    }
    return total >= human;
}

void bfs(int pos, int x, int y)
{
    memset(vis,0,sizeof vis);
    queue< pair<int,int> > qu;
    vis[x][y] = 1;
    qu.push(make_pair(x,y));
    while(!qu.empty())
    {
        x = qu.front().first;
        y = qu.front().second;
        qu.pop();
        if(str[x][y] == 'H')
        {
            dis[pos][no_human[x][y]] = vis[x][y];
        }
        for(int i = 0; i < 4; i++)
        {
            int tx = x+xx[i];
            int ty = y+yy[i];
            if(tx < 0 || tx >= row || ty < 0 || ty >= col) continue;
            if(vis[tx][ty] != 0 || str[tx][ty] == '#') continue;
            vis[tx][ty] = vis[x][y]+1;
            qu.push(make_pair(tx,ty));
        }
    }
}

int binary()
{
    int st = 1;
    int en = inf+10;
    int mid;
    while(st <= en)
    {
        mid = (st+en)/2;
        if(bpm(mid)) en = mid-1;
        else st = mid+1;
    }
    if(!bpm(en)) en++;
    return en;
}

int main()
{

    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &row);
        col = row;
        human = 0;
        memset(no_human,-1,sizeof no_human);
        for(int i = 0; i < row; i++)
        {
            scanf(" %s", str[i]);
            for(int j = 0; j < col; j++)
            {
                if(str[i][j] == 'H')
                {
                    no_human[i][j] = human++;
                }
            }
        }
        n = 0;
        memset(dis,-1,sizeof dis);

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(str[i][j] == 'G')
                {
                    for(int k = 0; k <= human; k++)

                        bfs(n,i,j);
                    n++;
                }
            }
        }
        /*for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < human; j++)
            printf("%d ", dis[i][j]);
            puts("");
        }*/
        printf("Case %d: ", te);
        int ans = binary();
        if(ans >= inf)
            printf("Vuter Dol Kupokat");
        else
            printf("%d", ans<<1);
        puts("");
    }
    return 0;
}

