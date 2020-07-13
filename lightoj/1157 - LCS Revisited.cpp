#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct data{int len, sul;
    data(){}
    data(int a, int b)
    {
        len = a, sul = b;
    }
};

data dp[1002][1002];
int len1, len2;
char str1[1005], str2[1005];

data maxi(data a, data b)
{
    if(a.len > b.len) return a;
    if(a.len < b.len) return b;
    if(a.len == 0) return data(0,1);
    return data(a.len,(a.sul+b.sul)%1000007);
}

data func(int i, int j)
{
    if(i == len1 && j == len2) return data(0,1);
    if(i > len1 || j > len2) return data(-10000,0);
    data & res = dp[i][j];
    if(res.len != -1) return res;
    if(str1[i] == str2[j])
        res = data(func(i+1,j+1).len+1,func(i+1,j+1).sul);
    if(i < len1)
        res = maxi(res,func(i+1,j));
    if(j < len2)
        res = maxi(res,func(i,j+1));
    return res;
}
int main()
{
    int te , ti;
    scanf("%d", &ti);
    gets(str1);
    for(te = 1; te <= ti; te++)
    {
        gets(str1);
        gets(str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        memset(dp,-1,sizeof dp);
        int res = func(0,0).sul;
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
