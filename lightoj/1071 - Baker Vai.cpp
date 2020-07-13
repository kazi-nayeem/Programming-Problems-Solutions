#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;

#define inf (1<<20)

int dp[101][101][101];
int row, col, arr[101][101];

int func(int lev, int fs, int se)
{
    if((lev == (col-1)) && ((fs+2) == row)) return arr[fs][lev]+arr[se][lev-1];
    int & res = dp[lev][fs][se];
    if(res != -1) return res;
    res = -inf;
    if(lev+1 < col)
        res = func(lev+1,fs,se)+arr[fs][lev]+arr[se][lev-1];
    if(se+1 < row)
        res = max(res, func(lev,fs,se+1)+arr[se][lev-1]);
    if(fs+1 < se)
        res = max(res, func(lev,fs+1,se)+arr[fs][lev]);
    //printf("%d %d %d %d\n", lev, fs, se, res);
    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &row, &col);
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);
        printf("Case %d: %d\n", te, arr[0][0]+arr[row-1][col-1]+func(1,0,1));
    }
    return 0;
}
