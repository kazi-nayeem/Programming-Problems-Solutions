#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long
#define MX 100005
#define inf 100000000

int row, col, present;
int dp[8][1<<8][1<<8];
char cas[8][1<<8][1<<8];
char str[10][10];

int func(int pos, int pre, int now);

int getmask(int pos)
{
    int mask = 0;
    for(int i = 0; i < col; i++)
        if(str[pos][i] == '*')
            mask |= 1<<i;
    return mask;
}

int changemask(int mask, int pos)
{
    if(pos > 0)
        mask ^= (1<<(pos-1));
    mask ^= 1<<pos;
    if(pos+1 < col)
        mask ^= 1<<(pos+1);
    return mask;
}

int generat(int r,int c,int pre,int now,int next)
{
    if(c == col)
    {
        if((r == 0) || (pre == ((1<<col)-1)))
            return func(r+1,now,next);
        return inf;
    }

    int res = inf;
    res = generat(r,c+1,pre,now,next);
    res = min(res,generat(r,c+1,changemask(pre,c),changemask(now,c),changemask(next,c))+1);
    return res;
}

int func(int pos, int pre, int now)
{
    if(pos == row)
    {
        if(pre == ((1<<col)-1)) return 0;
        return inf;
    }
    int & res = dp[pos][pre][now];
    if(cas[pos][pre][now] == present) return res;
    cas[pos][pre][now] = present;
    res = generat(pos,0,pre,now,getmask(pos+1));
    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &row, &col);
        for(int i = 0; i < row; i++)
            scanf(" %s", str[i]);
        present++;
        int res = func(0,0,getmask(0));
        if(res == inf)
            printf("Case %d: impossible\n", te);
        else
            printf("Case %d: %d\n", te, res);
    }
    return 0;
}
