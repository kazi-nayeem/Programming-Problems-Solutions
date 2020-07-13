#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long int ll;

struct data
{
    int le;
    ll sul;
    data() {};
    data(int a, ll b)
    {
        le = a,sul=b;
    }
};

char str1[35], str2[35];
data dp[31][31];
int len1, len2;

data mini(data a, data b)
{
    if(a.le < b.le) return data(a.le,a.sul);
    if(b.le < a.le) return data(b.le,b.sul);
    return data(a.le,a.sul+b.sul);
}

data func(int i,int j)
{
    if((i ==len1&&j==len2)) return data(0,1);

    data & res = dp[i][j];
    if(res.le != -1) return res;

    res.le = 100000;
    data tem;

    if(str1[i] == str2[j])
       return res = data(func(i+1,j+1).le+1, func(i+1,j+1).sul);
    if(j<len2)
    {
        tem = data(func(i,j+1).le+1, func(i,j+1).sul);
        res = mini(tem,res);
    }
    if(i<len1)
    {
        tem = data(func(i+1,j).le+1, func(i+1,j).sul);
        res = mini(tem,res);
    }
    return res;
}

/*int func(int i,int j)
{
    if((i ==len1&&j==len2)||(j ==len2&&i==len1)) return 0;
    if(i > len1 || j > len2) return 1000;
    int & res = dp[i][j];
    if(res != -1) return res;
    int tem;
    res = 1000;
    if(str1[i] == str2[j])
    {
        res = func(i+1,j+1)+1;
        //printf("%d %d %d %d\n", i,j, res.le, res.sul);
    }
    tem = func(i,j+1)+1;
    res = min(tem,res);
    tem = func(i+1,j)+1;
    res = min(tem,res);
    //printf("%d %d %d\n", i, j, res);
    return res;
}*/

int main()
{
    int te, ti;
    scanf("%d", &ti);
    gets(str1);

    for(te = 1; te <= ti; te++)
    {
        gets(str1);
        gets(str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        memset(dp,-1,sizeof dp);
        data result = func(0,0);
        printf("Case %d: %d %lld\n", te, result.le, result.sul);
    }
    return 0;
}
