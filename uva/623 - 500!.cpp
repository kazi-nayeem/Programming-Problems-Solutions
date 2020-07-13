#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define ll long long
#define MX 6000
#define MXP 78537

char str[1005][MX];

void calc(void)
{
    str[0][MX-1] = 1;
    for(int i = 1; i <= 1000; i++)
    {
        ll sum = 0;
        for(int j = MX-1; j >= 0; j--)
        {
            sum += str[i-1][j]*i;
            str[i][j] = sum%10LL;
            sum/=10;
        }
    }
}

int main()
{
//    double res = 0;
//    for(int i = 1; i <= 1000; i++)
//        res += log(i);
//    printf("%lf\n", res);
    calc();
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("%d!\n", n);
        int flag = 0;
        for(int i = 0; i < MX; i++)
        {
            if(flag || str[n][i])
            {
                printf("%d", str[n][i]);
                flag = 1;
            }
        }
        puts("");
    }
    return 0;
}
