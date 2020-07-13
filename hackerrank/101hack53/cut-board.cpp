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
#include<complex>
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

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

struct data
{
    int x, y, d;
    data() {}
    data(int x, int y): x(x), y(y) {}
    data(int x, int y, int d): x(x), y(y), d(d) {}
    bool operator < (const data & p) const
    {
        if(d != p.d) return d>p.d;
        if(y != p.y) return y>p.y;
        return x>p.x;
    }
};

int deg[MX][MX];
int grid[MX][MX];
int n, m;

bool check(int x, int y)
{
    return x>=1 && y >=1 && x <= n && y <= m;
}

vector< pair<data,data> > res;

bool func(int a, int b)
{
    for(int i = 1; i <= a; i++)
        grid[1][i] = 1;
    for(int i = 1; i <= b; i++)
        grid[n][m-i+1] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int x = xx[k]+i;
                int y = yy[k]+j;
                if(!check(x,y))
                    continue;
                if(grid[x][y] == 0)
                    deg[i][j]++;
            }
        }
    priority_queue<data> qu;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            qu.push(data(i,j,deg[i][j]));
    while(!qu.empty())
    {
        int x = qu.top().x;
        int y = qu.top().y;
        int d = qu.top().d;

        qu.pop();

        if(grid[x][y] == 1)
            continue;
        int tx, ty, f = 0;
        for(int i = 0; i < 4; i++)
        {
            tx = xx[i]+x;
            ty = yy[i]+y;
            if(!check(tx,ty))
                continue;
            if(grid[tx][ty])
                continue;
            f = 1;
            break;
        }
        if(f == 0)
            return false;
        res.push_back(make_pair(data(x,y,0),data(tx,ty,0)));
        grid[x][y] = 1;
        grid[tx][ty] = 1;

        for(int i = 0; i < 4; i++)
        {
            int ttx = xx[i]+x;
            int tty = yy[i]+y;
            if(!check(ttx,tty))
                continue;
            if(grid[ttx][tty])
                continue;
            deg[ttx][tty]--;
            qu.push(data(ttx,tty,deg[ttx][tty]));
        }

        for(int i = 0; i < 4; i++)
        {
            int ttx = xx[i]+tx;
            int tty = yy[i]+ty;
            if(!check(ttx,tty))
                continue;
            if(grid[ttx][tty])
                continue;
            deg[ttx][tty]--;
            qu.push(data(ttx,tty,deg[ttx][tty]));
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    if(func(x,y))
    {
        puts("YES");
        printf("%d\n", res.size());
        for(int i = 0; i < res.size(); i++)
        {
            printf("%d %d %d %d\n", res[i].first.x, res[i].first.y, res[i].second.x, res[i].second.y);
        }
    }
    else
    {
        puts("NO");
    }
    return 0;
}


