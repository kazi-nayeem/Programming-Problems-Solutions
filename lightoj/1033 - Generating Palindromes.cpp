#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int dp[101][101];
char str[105];

int func(int i, int j);

int main()
{
    //freopen("input.txt","r", stdin);
    int te, ti;
    scanf("%d", &ti);
    gets(str);
    for(te = 1; te <= ti; te++)
    {
        gets(str);
        int len = strlen(str);
        memset(dp, -1, sizeof dp);
        int k = func(0,len-1);
        printf("Case %d: %d\n", te, k);
    }
    return 0;
}

int func(int i, int j)
{
    if(i >= j) return 0;
    int & res = dp[i][j];
    if(res != -1) return res;

    int ret1 = 1000, ret2 = 1000, ret3 = 1000;
    if(str[i] == str[j])
        ret1 = func(i+1,j-1);

    ret2 = func(i,j-1)+1;
    ret3 = func(i+1,j)+1;
    res = min(ret1, min(ret2,ret3));
    return res;
}
