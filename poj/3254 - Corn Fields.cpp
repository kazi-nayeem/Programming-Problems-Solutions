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
using namespace std;

#define ll long long
#define MX 100005
#define inf 100000000

const int mod = 100000000;

int arr[15][15];
int row, col;
int dp[12][1<<12];

int genera(int r, int c, int pre, int now);

int func(int pos, int mask)
{
    if(pos == row) return 1;
    int &res = dp[pos][mask];
    if(res != -1) return res;
    res = genera(pos,0,mask,0);
    return res;
}

int genera(int r, int c, int pre, int now)
{
    if(c >= col) return func(r+1,now);
    if(arr[r][c] == 0) return genera(r,c+1,pre,now);
    int res = 0;
    if(((pre>>c)&1) == 0)
        res = genera(r,c+2,pre,now | (1<<c));
    res += genera(r,c+1,pre,now);
    return res%mod;
}

int main()
{
    while(scanf("%d%d", &row, &col) == 2)
    {
        memset(arr,0,sizeof arr);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                scanf("%d", &arr[i][j]);
        memset(dp,-1,sizeof dp);
        printf("%d\n", func(0,0));
    }
    return 0;
}

