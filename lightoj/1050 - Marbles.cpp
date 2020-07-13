#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
using namespace std;

#define MX 502

double dp[MX][MX];

double fun(int red, int blue)
{
    if(red == 0 && blue == 1) return 1.0;
    if(blue == 0) return 0.0;
    if(red < 0 || blue < 0) return 0.0;
    double & res = dp[red][blue];
    if(res != -1.0) return res;
    res = (double)((double)red/(red+blue))*fun(red-1,blue-1);
    res += (double)((double)blue/(red+blue))*fun(red,blue-2);
    return res;
}

int main()
{
    for(int i = 0; i < MX; i++)
        for(int j = 0; j < MX; j++)
            dp[i][j] = -1.0;
    int te, ti, r, b;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &r, &b);
        printf("Case %d: %.10lf\n", te, fun(r,b));
    }
    return 0;
}
