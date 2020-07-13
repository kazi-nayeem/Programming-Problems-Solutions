#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int len[3];
char str[3][60];
int dp[51][51][51];

int func(int i, int j, int k);

int main()
{
    //freopen("input.txt", "r", stdin);
    int te, ti;
    scanf("%d", &ti);
    gets(str[0]);

    for(te = 1; te <= ti; te++)
    {
        gets(str[0]);
        for(int i = 0; i < 3; i++)
        {
            gets(str[i]);
            len[i] = strlen(str[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n", te, func(0,0,0));
    }
    return 0;
}

int func(int i, int j, int k)
{
    if(i>=len[0] || j >= len[1] || k >= len[2]) return 0;

    int & res = dp[i][j][k];
    if(res != -1) return res;

    int ret1 = 0, ret2, ret3, ret4;
    if(str[0][i] == str[1][j] && str[0][i] == str[2][k])
        ret1 = func(i+1,j+1,k+1)+1;

    ret2 = func(i+1,j,k);
    ret3 = func(i,j+1,k);
    ret4 = func(i,j,k+1);

    res = max(max(ret1,ret2),max(ret3,ret4));
    return res;
}
