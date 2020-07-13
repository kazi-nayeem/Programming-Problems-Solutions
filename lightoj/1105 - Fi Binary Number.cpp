#include<cstdio>
#include<cstring>

#define MX 42

int dp[MX][2][2];

int func(int pos, int pre, int now)
{
    if(pre == now && pre == 1) return 0;
    if(pos == MX) return 1;
    int & res = dp[pos][pre][now];
    if(res != -1) return res;
    res = func(pos+1,now,0);
    res += func(pos+1,now,1);
    return res;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int te, ti;
    int n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        n++;
        printf("Case %d: ", te);
        int pre = 0, flag = 0;
        for(int i = 0; i <= MX; i++)
        {
            int res = func(i,pre,0);
            if(res >= n)
            {
                if(flag)
                    putchar('0');
                pre = 0;
            }
            else
            {
                flag = 1;
                putchar('1');
                pre = 1;
                n -= res;
            }
        }
        puts("");
    }
    return 0;
}

