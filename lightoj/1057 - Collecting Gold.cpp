#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

int dp[1<<15][15];
int arr[15];
int row, col, sten, fini, pos;

int dist(int a, int b);
int func(int mask, int now);

int main()
{
    int te, ti;
    char ch;
    scanf("%d", &ti);
    for(int te = 1; te <= ti; te++)
    {
        scanf("%d%d", &row, &col);
        pos = 0;
        for(int i = 0; i < row; i++)
        {
            getchar();
            for(int j = 0; j < col; j++)
            {
                ch = getchar();
                if(ch == 'g')
                    arr[pos++] = (i*col)+j;
                else if(ch == 'x')
                    sten = (i*col)+j;
            }
        }
        fini = (1<<pos) - 1;
        int ans = 10000000;
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < pos; i++)
            ans = min(ans, func(1<<i,i)+dist(sten,arr[i]));
        if(pos == 0) ans = 0;
        printf("Case %d: %d\n", te, ans);
    }
    return 0;
}

int dist(int a, int b)
{
    int dr = abs((a/col)-(b/col));
    int dc = abs((a%col)-(b%col));
    int dif = min(dr,dc);
    return dr+dc-dif;
}

int func(int mask, int now)
{
    if(mask == fini)
    {
        return dist(sten,arr[now]);
    }
    int & res = dp[mask][now];
    if(res != -1) return res;
    res = 10000000;
    for(int i = 0; i < pos; i++)
        if(((mask>>i)&1) == 0)
    {
        res = min(res, func((mask|(1<<i)),i)+dist(arr[now],arr[i]));
    }
    return res;
}
