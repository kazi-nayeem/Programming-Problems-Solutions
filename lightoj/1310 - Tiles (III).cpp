#include<cstdio>
#include<iostream>
using namespace std;

#define inf 100000000

int row, col;
int power[10];
char str[101][10];
int dp[100][6561], _save;
char __save[100][6561];

int func(int pos, int mask);

int type(int mask,int pos)
{
    return (mask/power[pos])%3;
}

int assig(int mask, int pos, int val)
{
    return mask+((val-type(mask,pos))*power[pos]);
}

int genera(int r, int c, int mask)
{
    if(c == col) return func(r+1,mask);
    int res = 0;
    if(type(mask,c) > 0)
    {
        if(str[r][c] == '#') return -inf;
        return genera(r,c+1,assig(mask,c,type(mask,c)-1));
    }
    else if(str[r][c] == '#')
    {
        return genera(r,c+1,mask);
    }
    else
    {
        res = max(res, genera(r,c+1,mask));
    }
    if((r+1 < row) && (c+2 < col) && type(mask,c+1) == 0 && type(mask,c+2) == 0)
    {
        bool flag = true;
        for(int i = c; i <= c+2; i++)
            for(int j = r; j <= r+1; j++)
                if(str[j][i] == '#')
                {
                    flag = false;
                    break;
                }
        if(flag)
        {
            int tem = assig(mask,c,1);
            tem = assig(tem,c+1,1);
            tem = assig(tem,c+2,1);
            res = max(res,genera(r,c+3,tem)+1);
        }
    }
    if((r+2 < row) && (c+1 < col) && type(mask,c+1) == 0)
    {
        bool flag = true;
        for(int i = c; i <= c+1; i++)
            for(int j = r; j <= r+2; j++)
                if(str[j][i] == '#')
                {
                    flag = false;
                    break;
                }
        if(flag)
        {
            int tem = assig(mask,c,2);
            tem = assig(tem,c+1,2);
            res = max(res,genera(r,c+2,tem)+1);
        }
    }
    return res;
}

int func(int pos, int mask)
{
    if(pos == row)
    {
        if(mask == 0) return 0;
        return -inf;
    }
    int & res = dp[pos][mask];
    if(__save[pos][mask] == _save) return res;
    __save[pos][mask] = _save;
    res = 0;
    res = max(res,genera(pos,0,mask));
    return res;
}

int main()
{
    power[0] = 1;
    for(int i = 1; i <= 8; i++)
        power[i] = 3*power[i-1];

    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++ )
    {
        scanf("%d %d", &col, &row);
        for(int i = 0; i < col; i++)
        {
            getchar();
            for(int j = 0; j < row; j++)
                str[j][i] = getchar();
        }
        _save++;
        printf("Case %d: %d\n", te, func(0,0));
    }
    return 0;
}
