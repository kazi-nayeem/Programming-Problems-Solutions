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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};
int cnt;
char str[100][100];
int row, col;

void dfs(int x, int y, char ch)
{
    if(str[x][y] != ch) return;
    cnt++;
    str[x][y] = 'X';
    for(int i = 0; i < 4; i++)
    {
        int tx = x+xx[i];
        int ty = y+yy[i];
        if(tx < 0 || ty < 0 || tx>=row || ty>=col) continue;
        dfs(tx,ty,ch);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d", &col, &row) == 2)
    {
        for(int i = 0; i < row; i++)
            scanf("%s", str[i]);
        int toli = 0, tas = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(str[i][j] == 'X') continue;
                if(str[i][j] == '*')
                {
                    cnt = 0;
                    dfs(i,j,'*');
                    toli = max(toli,cnt);
                }
                if(str[i][j] == '.')
                {
                    cnt = 0;
                    dfs(i,j,'.');
                    tas = max(tas,cnt);
                }
            }
        //printf("%d %d\n", toli, tas);
        if(toli>tas)
            puts("TULTUL WINS THE ROUND.");
        else if(toli<tas)
            puts("TASFIA WINS THE ROUND.");
        else
            puts("NOBODY LOSES.");
    }
    return 0;
}

