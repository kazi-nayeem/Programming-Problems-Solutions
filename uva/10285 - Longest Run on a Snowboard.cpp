#include<cstdio>
#include<cstring>
using namespace std;

#define MX 101

int x[] = {0,0,-1,1};
int y[] = {-1,1,0,0};
int arr[MX][MX], dp[MX][MX], row, colum;

int dfs(int r, int c);

int main()
{
    char str[1000], ti;
    scanf("%d", &ti);

    while(ti--)
    {
        scanf("%s%d%d", str, &row, &colum);
        //printf(" %s %d %d\n", str, row, colum);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < colum; j++)
            scanf("%d", &arr[i][j]);
        int mxi = 0, tem;
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < colum; j++)
        {
            tem = dfs(i,j);
            if(tem > mxi) mxi = tem;
        }
        printf("%s: %d\n", str, mxi+1);
    }
    return 0;
}

int dfs(int r, int c)
{
    if(r < 0 || r >= row || c < 0 || c >= colum) return 0;
    int & res = dp[r][c];
    if(res != -1) return res;
    int temi, temj, mx = 0, dis;
    for(int i = 0; i < 4; i++)
    {
        temi = r+x[i];
        temj = c+y[i];
        if(temi < 0 || temi >= row || temj < 0 || temj >= colum) continue;
        if(arr[r][c] <= arr[temi][temj]) continue;
        dis = dfs(temi,temj)+1;
        if(mx < dis) mx = dis;
    }
    return res = mx;
}
