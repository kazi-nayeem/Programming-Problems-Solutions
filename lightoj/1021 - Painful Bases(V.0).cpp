#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
using namespace std;

#define ll long long int

int arr[20];
int n, k, len;
ll dp[1<<16][20];

ll rec(int mask, int mod, int tk)
{
    if(tk == len)
    {
        if(mod == 0) return 1;
        return 0;
    }
    ll & res = dp[mask][mod];
    if( res != -1) return res;
    res = 0LL;
    for(int i = 0; i < len; i++)
        if(((mask >> i) & 1) == 0)
            res += rec((mask|(1<<i)),(mod*n+arr[i])%k,tk+1);
    return res;
}

int main()
{
    int te, ti;
    char str[20];
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d %s", &n, &k, str);
        len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            if(str[i]>'9')
                arr[i] = (int) str[i]-'A'+10;
            else
                arr[i] = (int) str[i]-'0';
        }
        memset(dp,-1,sizeof dp);
        ll res = rec(0,0,0);
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
