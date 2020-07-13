#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define ll long long
#define MX 100050
#define inf 1000000

int row, col, now;

int dp[1<<16];
char str[10][10];

inline int type(int mask, int row, int col)
{
    return (mask>>((row<<2)+col))&1;
}


inline int assig(int mask, int row, int col)
{
    return mask | (1<<((row<<2)+col));
}

int func(int mask)
{
    //printf("%d %d %d %d %d %d\n", r, c, type(mask,0),type(mask,1), type(mask,2), type(mask,3));
    //getchar();
    if((1<<16) == (mask+1)) return 1;
    /*for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        printf("%d", type(mask,i,j));
        puts("");
    }
    puts("\n\n");*/
    int & res = dp[mask];
    if(res != -1) return res;
    res = 0;
    for(int i = 1; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if((type(mask,i,j) == 0))
                res = max(res,(func(assig(mask,i,j))+1)&1);
    if(res) return res;
    for(int i = 0; i < 4; i++)
        if(type(mask,i,0) == 0)
        {
            int tem = assig(mask,i,0);
            res = max(res,(func(tem)+1)&1);
            if(res) return res;
            for(int k = 1; k < 3; k++)
            {
                if(type(tem,i,k) == 1) break;
                tem = assig(tem,i,k);
                res = max(res,(func(tem)+1)&1);
                if(res) return res;
            }
        }
    for(int i = 0; i < 4; i++)
        if(type(mask,i,3) == 0)
        {
            int tem = assig(mask,i,3);
            res = max(res,(func(tem)+1)&1);
            if(res) return res;
            for(int k = 2; k > 0; k--)
            {
                if(type(tem,i,k) == 1) break;
                tem = assig(tem,i,k);
                res = max(res,(func(tem)+1)&1);
                if(res) return res;
            }
        }

    for(int i = 0; i < 4; i++)
        if(type(mask,0,i) == 0)
        {
            int tem = assig(mask,0,i);
            res = max(res,(func(tem)+1)&1);
            if(res) return res;
            for(int k = 1; k < 3; k++)
            {
                if(type(tem,k,i) == 1) break;
                tem = assig(tem,k,i);
                res = max(res,(func(tem)+1)&1);
                if(res) return res;
            }
        }
    for(int i = 0; i < 4; i++)
        if(type(mask,3,i) == 0)
        {
            int tem = assig(mask,3,i);
            res = max(res,(func(tem)+1)&1);
            if(res) return res;
            for(int k = 2; k > 0; k--)
            {
                if(type(tem,k,i) == 1) break;
                tem = assig(tem,k,i);
                res = max(res,(func(tem)+1)&1);
                if(res) return res;
            }
        }
    return res;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        for(int i = 0; i < 4; i++)
            scanf(" %s", str[i]);
        int mask = 0;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(str[i][j] == 'X')
                    mask |= 1<<(i*4+j);
        if(func(mask) == 1) puts("WINNING");
        else puts("LOSING");
    }
    return 0;
}
