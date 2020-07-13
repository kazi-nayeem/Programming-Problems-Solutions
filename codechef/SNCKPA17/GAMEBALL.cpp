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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
int xx[] = {0,0,-1,1};
int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 105
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    int a, b, c, d;
    data(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
};

int row, col;
char str[MX][MX];

bool needmove()
{
    int cnt = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(str[i][j] == '*')
            {
                if(cnt) return true;
                cnt++;
            }
        }
    }
    return false;
}

vector<data> res;

int dist[MX][MX];

void mindist(int x, int y, int p, int q)
{
    queue<pii> qu;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            dist[i][j] = -1;
        }
    qu.push(make_pair(x,y));
    dist[x][y] = 0;
    while(!qu.empty())
    {
        int x = qu.front().first;
        int y = qu.front().second;
        for(int i = 0; i < 4; i++)
        {
            int tx = x+xx[i];
            int ty = y+yy[i];
            if(tx == p && ty == q) continue;
            if(tx<0 || ty < 0 || tx >= row || ty >= col) continue;
            if(dist[tx][ty] != -1) continue;
            dist[tx][ty] = dist[x][y]+1;
            qu.push(make_pair(tx,ty));
        }
    }
    int mi = 1000, a, b;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(i == p && j == q) continue;
            if(str[i][j] == '*')
            {
                if(mi>dist[i][j])
                {
                    mi = dist[i][j];
                    a = i;
                    b = j;
                }
            }
        }
    str[a][b] = '.';
    while(a != x || b != y)
    {
        for(int i = 0; i < 4; i++)
        {
            int tx = x+xx[i];
            int ty = y+yy[i];
            if(tx<0 || ty < 0 || tx >= row || ty >= col) continue;
            if(dist[tx][ty]+1 != dist[a][b]) continue;
            res.push_back(data(a,b,tx,ty));
            a = tx;
            b = ty;
            break;
        }
    }
}

void moveone()
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(i>=2 && str[i][j] == '.' && str[i-1][j] == '*' && str[i-2][j] == '*')
            {
                res.push_back(data(i-2,j,i,j));
                str[i][j] = '*';
                str[i-1][j] = '.';
                str[i-2][j] = '.';
                return;
            }
            if(j>=2 && str[i][j] == '.' && str[i][j-1] == '*' && str[i][j-2] == '*')
            {
                res.push_back(data(i,j-2,i,j));
                str[i][j] = '*';
                str[i][j-1] = '.';
                str[i][j-2] = '.';
                return;
            }
            if(i+2< row && str[i][j] == '.' && str[i+1][j] == '*' && str[i+2][j] == '*')
            {
                res.push_back(data(i+2,j,i,j));
                str[i][j] = '*';
                str[i+1][j] = '.';
                str[i+2][j] = '.';
                return;
            }
            if(j+2<col && str[i][j] == '.' && str[i][j+1] == '*' && str[i][j+2] == '*')
            {
                res.push_back(data(i,j+2,i,j));
                str[i][j] = '*';
                str[i][j+1] = '.';
                str[i][j+2] = '.';
                return;
            }
        }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(i>=2 && str[i][j] == '.' && str[i-1][j] == '*' && str[i-2][j] == '.')
            {
                mindist(i-2,j,i-1,j);
                res.push_back(data(i-2,j,i,j));
                str[i][j] = '*';
                str[i-1][j] = '.';
                str[i-2][j] = '.';
                return;
            }
            if(j>=2 && str[i][j] == '.' && str[i][j-1] == '*' && str[i][j-2] == '.')
            {
                mindist(i,j-2,i,j-1);
                res.push_back(data(i,j-2,i,j));
                str[i][j] = '*';
                str[i][j-1] = '.';
                str[i][j-2] = '.';
                return;
            }
            if(i+2< row && str[i][j] == '.' && str[i+1][j] == '*' && str[i+2][j] == '.')
            {
                mindist(i+2,j,i+1,j);
                res.push_back(data(i+2,j,i,j));
                str[i][j] = '*';
                str[i+1][j] = '.';
                str[i+2][j] = '.';
                return;
            }
            if(j+2<col && str[i][j] == '.' && str[i][j+1] == '*' && str[i][j+2] == '.')
            {
                mindist(i,j+2,i,j+1);
                res.push_back(data(i,j+2,i,j));
                str[i][j] = '*';
                str[i][j+1] = '.';
                str[i][j+2] = '.';
                return;
            }
        }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(j+1<col && str[i][j] == '*' && str[i][j+1] == '.')
            {
                res.push_back(data(i,j,i,j+1));
                str[i][j] = '.';
                str[i][j+1] = '*';
                return;
            }
            if(i+1<row && str[i][j] == '*' && str[i][j+1] == '.')
            {
                res.push_back(data(i,j,i,j+1));
                str[i][j] = '.';
                str[i][j+1] = '*';
                return;
            }
        }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    while(ti--)
    {
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++)
            scanf("%s", str[i]);
        res.clear();
        while(needmove())
        {
            moveone();
        }
    }
    return 0;
}


