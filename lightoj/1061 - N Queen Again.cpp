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

int res[100][8], solve;
int arr[8];

void backtrack(int pos)
{
    if(pos == 8)
    {
        for(int i = 0; i < 8; i++)
            res[solve][i] = arr[i];
        solve++;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        bool flag = true;
        for(int j = 0; j < pos; j++)
        {
            if(arr[j] == i || (arr[j] == (i-(pos-j))) || (arr[j] == (i+(pos-j))))
            {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        arr[pos] = i;
        backtrack(pos+1);
    }
    return;
}

int dp[1<<8];
int _save[1<<8], save;
pair<int,int> maze[8];

int func(int mask, int pos, int now)
{
    if(pos == 8) return 0;
    int & ret = dp[mask];
    if(_save[mask]  == save) return ret;
    _save[mask] = save;
    ret = inf;
    for(int i = 0; i < 8; i++)
    {
        if((mask>>i)&1) continue;
        if(maze[i].first == pos && maze[i].second == res[now][pos])
            ret = min(ret,func(mask | (1<<i),pos+1,now));
        else if(maze[i].first == pos || maze[i].second == res[now][pos] || abs(maze[i].first-pos) == abs(maze[i].second - res[now][pos]))
            ret = min(ret,func(mask | (1<<i),pos+1,now)+1);
        else
            ret = min(ret,func(mask | (1<<i),pos+1,now)+2);
    }
    return ret;
}

char str[10][10];

int main()
{
    backtrack(0);
//    printf("%d\n", solve);
//    for(int i = 0; i < 8; i++)
//        printf("%d ", res[0][i]);
//    puts("");
    int te, ti;
    scanf("%d", &ti);
    gets(str[0]);
    for(te = 1; te <= ti; te++)
    {
        gets(str[0]);
        for(int i = 0; i < 8; i++)
            gets(str[i]);
        int pos = 0;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
        {
            if(str[i][j] == 'q')
                maze[pos++] = make_pair(i,j);
        }
        int res = inf;
        for(int i = 0; i < solve; i++)
        {
            save++;
            res = min(res,func(0,0,i));
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}

