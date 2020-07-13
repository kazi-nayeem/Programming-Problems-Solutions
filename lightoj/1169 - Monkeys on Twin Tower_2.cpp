#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int dp[1001][1001][2];
int arr[2][1001];
int jump[2][1001];
int n;

int func(int pos, int tak, int tow);

int main()
{
    int ti, te;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j +1 < n; j++)
            scanf("%d", &jump[i][j]);
        memset(dp,-1,sizeof dp);
        int mini = func(0,n,0);
        mini = min(mini,func(0,n,1));
        printf("Case %d: %d\n", te, mini);
    }
    return 0;
}

int func(int pos, int tak, int tow)
{
    if(tak <= 0)
    {
        return 0;
    }
    if(pos >= n) return 100000000;

    int & res = dp[pos][tak][tow];
    if(res != -1) return res;
    int ret1 = 100000000, ret2 = 100000000;
    ret1 = min(func(pos+1,tak-1,tow)+arr[tow][pos], func(pos+1,tak,tow));
    ret2 = min(func(pos+1,tak-1,(tow+1)%2)+arr[tow][pos]+jump[tow][pos], func(pos+1,tak,(tow+1)%2)+jump[tow][pos]);

    return res = min(ret1,ret2);
}

