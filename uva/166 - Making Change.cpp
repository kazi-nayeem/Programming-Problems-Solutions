#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 120

int dp[MAX][6];
int coin[] = {1,2,4,10,20,40};
int tak[6];

int coinchange(int i, int n);

int main()
{
    int normal[MAX];
    memset(normal, 50, sizeof normal);
    normal[0] = 0;
    for(int i = 5; i >= 0; i--)
        for(int j = coin[i]; j < MAX; j++)
        normal[j] = min(normal[j],normal[j-coin[i]]+1);

    int i, n, k, flag, in;
    int total;
    while(1)
    {
        flag = 1;
        total = 0;
        for(i = 0; i < 6; i++)
        {
            scanf(" %d", &tak[i]);
            total += tak[i]*coin[i];
            if(tak[i])
                flag = 0;
        }
        if(flag) return 0;

        total = min(total,MAX-1);
        scanf(" %d.%d", &n, &k);
        n = (n * 100) + k;
        n /= 5;

        memset(dp, -1, sizeof(dp));
        int result = coinchange(0,n);
        for(i = n+1;i<=total;i++)
            result = min(result, normal[i-n]+coinchange(0,i));

        printf("%3d\n", result);
    }
    return 0;
}

int coinchange(int i, int n)
{
    if(i >= 6)
    {
        if(n == 0) return 0;
        return 100000;
    }
    int & res = dp[n][i];
    if(res != -1) return res;

    int ret = 100000;
    for(int j = 0; j <= tak[i] && n >= j * coin[i]; j++)
        ret = min(ret,coinchange(i+1, n - j * coin[i])+j);

    return res = ret;
}
