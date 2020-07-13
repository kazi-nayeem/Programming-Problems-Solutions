#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

vector<string> str1, str2;
int dp[102][102], m, n, flag;

int func(int i, int j)
{
    if(i == m || j == n) return 0;
    int & res = dp[i][j];
    if(res != -1) return res;
    if(str2[j] == str1[i]) return res = func(i+1,j+1)+1;
    return res = max(func(i+1,j),func(i,j+1));
}
void print(int i, int j)
{
    if(i == m || j == n) return;
    if(str1[i] == str2[j])
    {
        if(flag) putchar(' ');
        flag = 1;
        cout<<str1[i];
        return print(i+1,j+1);
    }
    if(func(i+1,j) >= func(i,j+1)) return print(i+1,j);
    return print(i,j+1);
}
int main()
{
    char st[50];
    while(scanf(" %s", st) == 1)
    {
        str1.clear();
        str2.clear();
        if(strcmp(st,"#") != 0)
        {
            str1.push_back((string) st);
            while(scanf(" %s", st) == 1)
            {
                if(strcmp(st,"#") == 0) break;
                str1.push_back((string) st);
            }
        }
        while(scanf(" %s", st) == 1)
        {
            if(strcmp(st,"#") == 0) break;
            str2.push_back((string) st);
        }
        m = str1.size();
        n = str2.size();
        memset(dp,-1,sizeof dp);
        flag = 0;
        func(0,0);
        print(0,0);
        puts("");
    }
    return 0;
}
