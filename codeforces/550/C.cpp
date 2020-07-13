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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int dp[1000][8];
int dire[1000][8];
int flag[1000][8];
int len;
char str[10000];

int func(int pos, int pre)
{
    if(pos ==len)
    {
        if(pre == 0) return 0;
        return -1000;
    }
    int &res = dp[pos][pre];
    if(res != -1) return res;
    res = -1000;
    int res1 = func(pos+1,(pre*10+str[pos]-'0')%8)+1;
    int res2 = func(pos+1,pre);
    if(res1 > res2)
    {
        flag[pos][pre] = 1;
        dire[pos][pre] = (pre*10+str[pos]-'0')%8;
        return res = res1;
    }
    flag[pos][pre] = 0;
    dire[pos][pre] = pre;
    return res = res2;
}

int main()
{
    memset(dp,-1,sizeof dp);
    gets(str);
    len = strlen(str);
    int res = func(0,0);
    if(res <= 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int pos = 0, pre = 0;
    while(pos<len){
        if(flag[pos][pre] == 1) putchar(str[pos]);
        pre = dire[pos][pre];
        pos++;
    }
    puts("");
    return 0;
}


