#include<cstdio>
#include<cstring>
using namespace std;

#define MX 503

int dp[MX][MX];
int cs[MX][MX];
int uranium[MX][MX];
int radium[MX][MX];
int row, col, te, ti;

int func(int pos, int op)
{
    if(pos == row+1 || op-1 > col) return 0;
    int & res = dp[pos][op];
    if(cs[pos][op] == te) return res;
    cs[pos][op] = te;
    //res = func(pos+1,op)+uranium[pos][op-1]+radium[pos][op];
    res = func(pos,op+1);
    int res1 = func(pos+1,op)+uranium[pos][op]+radium[pos][op+1];
    if(res < res1) res = res1;
    //printf("%d %d %d\n", pos, op, res);
    return res;
}

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &row, &col);
       // memset(dp,-1,sizeof dp);

        for(int i = 0; i <= row; i++)
            radium[i][col+2] = uranium[i][col+2] = uranium[i][0] = radium[i][col+1] = uranium[i][col+1] = radium[i][0]=0;

        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                scanf("%d", &uranium[i][j]);

        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                scanf("%d", &radium[i][j]);

        for(int i = 1; i <= row; i++)
            for(int j = 0; j <= col; j++)
                uranium[i][j+1] += uranium[i][j];

        for(int i = 1; i <= row; i++)
            for(int j = col; j >= 0; j--)
                radium[i][j] += radium[i][j+1];

        printf("Case %d: %d\n", te, func(1,0));
    }
    return 0;
}
