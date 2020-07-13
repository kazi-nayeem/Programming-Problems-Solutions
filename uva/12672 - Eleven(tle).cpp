#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
using namespace std;

#define ll long long int
#define MOD 1000000007LL

ll dp[10][55][55][455];
ll ncr[55][55];
int arr[10], total;

ll nCr(int n, int r)
{
    if(n<r) return 0;
    if(n == r|| r == 0) return 1;
    if(ncr[n][r] != -1) return ncr[n][r];
    return ncr[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%MOD;
}

ll rec(int pos, int n1, int n2, int mod)
{
    //printf("%d %d %d %d\n", pos, n1, n2, mod);
    if(pos == 10)
    {
        if(n1 == 0 && n2 == 0 && ((total-2*mod)%11 == 0)) return 1;
        return 0;
    }
    if(n1 < 0 || n2 < 0) return 0;
    ll & res = dp[pos][n1][n2][mod];
    if(res != -1) return res;
    res = 0;
    if(pos == 0)
    {
        res = (nCr(n2,arr[0])*rec(pos+1,n1,n2-arr[0],mod))%MOD;
        for(int i = 1; i <= arr[0] && i < n1; i++)
            res =(res+ (nCr(n1-1,i)*nCr(n2,arr[0]-i)*rec(pos+1,n1-i,n2-arr[0]+i,mod)))%MOD;
    }
    else
    {
        for(int i = 0; i <= arr[pos] && i <= n1; i++)
            res =(res + (nCr(n1,i)*nCr(n2,arr[pos]-i)*rec(pos+1,n1-i,n2-arr[pos]+i,mod+(pos*i))))%MOD;
    }
    return res;
}

int main()
{
    memset(ncr,-1,sizeof ncr);
//    for(int i = 0; i < 10; i++)
//    {
//        for(int j = 0; j < 10; j++)
//            printf("%lld ", nCr(i,j));
//        puts("");
//    }
    char str[150];
    while(gets(str))
    {
        int len = strlen(str);
        memset(arr,0,sizeof arr);
        total = 0;
        for(int i = 0; i < len; i++)
        {
            arr[str[i]-'0']++;
            total += str[i]-'0';
        }
        //printf("%d\n", total);
        memset(dp,-1,sizeof dp);
        ll res = rec(0,(len+1)/2,len/2,0);
        printf("%lld\n", res);
    }
    return 0;
}
