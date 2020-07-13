#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char str[1005];
int dp[1005];
int len;

bool check(int i, int j);
int palindrome(int n);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    getchar();
    for(te = 1; te <= ti; te++)
    {
        gets(str);
        len = strlen(str);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", te, palindrome(0));
    }
}

int palindrome(int n)
{
    if(n >= len) return 0;
    if(dp[n] != -1) return dp[n];
    int ret;
    ret = 1 + palindrome(n+1);
    for(int i = n+1; i < len; i++)
    {
        if(check(n,i))
            ret = min(ret, palindrome(i+1)+1);
    }
    return dp[n] = ret;
}
bool check(int i, int j)
{
    for(;i < j; i++, j--)
        if(str[i] != str[j])
        return false;
    return true;
}
