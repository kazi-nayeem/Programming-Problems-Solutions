//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 105
#define inf 1000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int mat[MX][MX];
int dist[2][MX][MX];
int row, col;

void bfs(int x, int y, int k, int dis[MX][MX])
{
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            dis[i][j] = inf;
    queue<pair<int,int> > qu;
    qu.push(make_pair(x,y));
    dis[x][y] = 0;
    int xx[4] = {1,1,-1,-1};
    int yy[4] = {1,-1,1,-1};
    while(!qu.empty())
    {
        x = qu.front().first;
        y = qu.front().second;

        qu.pop();
        //printf("%d %d\n", x, y);
        for(int i = 0; i <= k; i++)
        {
            for(int l = 0; l+i <= k; l++)
            {
                for(int j = 0; j < 4; j++)
                {
                    int tx = x+i*xx[j];
                    int ty = y+l*yy[j];
                    //printf("---%d %d\n",tx,ty);
                    if(tx < 1 || ty < 1 || ty > col || tx > row) continue;
                    if((dis[tx][ty] <= dis[x][y]+1) || (mat[tx][ty] == 1)) continue;

                    dis[tx][ty] = dis[x][y]+1;
                    qu.push(make_pair(tx,ty));
                }
            }
        }
    }
}

void bfs(int x, int y, int dis[MX][MX])
{
    //puts("ok");
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            dis[i][j] = inf;
    queue<pair<int,int> > qu;
    qu.push(make_pair(x,y));
    dis[x][y] = 0;
    int xx[4] = {0,0,1,-1};
    int yy[4] = {1,-1,0,0};

    while(!qu.empty())
    {
        x = qu.front().first;
        y = qu.front().second;

        qu.pop();
        //printf("%d %d\n", x, y);

        for(int j = 0; j < 4; j++)
        {
            int tx = x+xx[j];
            int ty = y+yy[j];
            //printf("---%d %d\n",tx,ty);
            if(tx < 1 || ty < 1 || ty > col || tx > row) continue;
            if((dis[tx][ty] <= dis[x][y]+1) || (mat[tx][ty] == 1)) continue;

            dis[tx][ty] = dis[x][y]+1;
            qu.push(make_pair(tx,ty));
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, k1, k2;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d %d %d", &row, &col, &k1, &k2);
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                scanf("%d", &mat[i][j]);
        if(k1 == 1)
            bfs(1,1,dist[0]);
        else
            bfs(1,1,k1,dist[0]);
        if(k2 == 1)
            bfs(1,col,dist[1]);
        else
            bfs(1,col,k2,dist[1]);
        int ans = inf;
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                ans = min(ans,max(dist[0][i][j],dist[1][i][j]));
        if(ans >= inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

