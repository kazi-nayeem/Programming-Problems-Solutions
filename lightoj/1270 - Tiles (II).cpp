#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

#define ll unsigned long long

int row, col;
char str[100][10];
ll dp[100][1<<8];
char __save[100][1<<8], _save;

ll func(char pos, char mask);

ll gener(char r, char c, char mask, char next)
{
    if(c == col) return func(r+1,next);
    if(str[r][c] == '#' || (((mask>>c)&1) == 1)) return gener(r,c+1,mask,next);
    ll res = 0llu;
    if(c+1<col && str[r][c+1] == '.' && ((mask>>(c+1))&1) == 0)
    {
        res += gener(r,c+2,mask | (3<<c),next);
        if(r+1<row)
        {
            if(str[r+1][c] == '.' && ((next>>c)&1) == 0)
                res += gener(r,c+2,mask | (3<<c),next | 1<<c);
            if(str[r+1][c+1] == '.' && ((next>>(c+1))&1) == 0)
                res += gener(r,c+2,mask | (3<<c),next | 1<<(c+1));
        }
    }
    if(r+1<row && str[r+1][c] == '.' && ((next>>c)&1) == 0)
    {
        res += gener(r,c+1,mask | (1<<c),next | (1<<c));
        if(c+1<col && str[r+1][c+1] == '.' && ((next>>(c+1))&1) == 0)
            res += gener(r,c+1,mask | (1<<c),next | (3<<c));
        if(c>0 && str[r+1][c-1] == '.' && ((next>>(c-1))&1) == 0)
            res += gener(r,c+1,mask | (1<<c),next | (3<<(c-1)));
    }

    return res;
}

ll func(char pos, char mask)
{
    if(pos == row)
    {
        if(mask == 0) return 1llu;
        return 0llu;
    }
    ll &res = dp[pos][mask];
    if(__save[pos][mask] == _save) return res;
    __save[pos][mask] = _save;
    res = gener(pos,0,mask,0);
    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &row, &col);
        if(row >= col)
        {
            gets(str[0]);
            for(int i = 0; i < row; i++)
                gets(str[i]);
        }
        else
        {
            row ^= col ^= row ^= col;
            for(int i = 0; i < col; i++)
            {
                getchar();
                for(int j = 0; j < row; j++)
                    str[j][i] = getchar();
            }
        }
        _save++;
        printf("Case %d: %llu\n", te, func(0,0));
    }
    return 0;
}
