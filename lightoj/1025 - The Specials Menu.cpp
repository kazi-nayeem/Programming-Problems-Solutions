#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long int ll;

ll dp[61][61];
char str[100];

ll func(int i, int j);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%s", str);
        int len = strlen(str);
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n", te, func(0,len-1));
    }
    return 0;
}

ll func(int i, int j)
{
    if(i > j) return 0;
    if(i == j) return 1;
    //printf("%d %d\n", i, j);
    ll & res = dp[i][j];
    if(res != -1) return res;

    ll ret = 0;
    if(str[i] == str[j])
        ret = func(i+1,j-1)+1;
    ret += func(i+1,j)+func(i,j-1)-func(i+1,j-1);

    return res = ret;
}
