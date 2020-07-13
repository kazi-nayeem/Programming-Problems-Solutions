#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

#define MAX 1010
#define FT first
#define SD second
#define MKP make_pair
#define pb push

void movefire(int i, int j);
int movejoe(int i, int j);
char maze[MAX][MAX];
int distence[MAX][MAX];
int row, colum;
bool posible;

int main()
{
    int time;
    scanf("%d", &time);
    while(time--)
    {
        scanf("%d %d", &row, &colum);
        getchar();
        for(int i = 0; i < row; i++)
            gets(maze[i]);
        bool fireflag = true, joeflag = true;
        pair<int , int> fire, joe;
        memset(distence, 0, sizeof distence);
        for(int i = 0,j; i < row; i++)
        {
            for(j = 0; j < colum; j++)
            {
                if(maze[i][j] == 'J')
                {
                    joe = MKP(i,j);
                }
                else if(maze[i][j] == 'F')
                {
                    movefire(i,j);
                }
            }
        }
        int dis = movejoe(joe.FT, joe.SD);
        if(posible)
            printf("%d\n", dis);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}

void movefire(int i, int j)
{
    queue< pair < pair < int ,int> , int> > next;
    next.pb(MKP(MKP(i,j), 1));
    distence[i][j] = 1;
    int dis;
    while(!next.empty())
    {
        i = next.front().FT.FT;
        j = next.front().FT.SD;
        dis = next.front().SD;
        next.pop();
        if(i>0)
        {
            if((distence[i-1][j] == 0 || distence[i-1][j] > dis+1) && maze[i-1][j] == '.')
            {
                next.pb(MKP(MKP(i-1,j), dis+1));
                distence[i-1][j] = dis+1;
            }
        }
        if(i+1<row)
        {
            if((distence[i+1][j] == 0 || distence[i+1][j] > dis+1) && maze[i+1][j] == '.')
            {
                next.pb(MKP(MKP(i+1,j), dis+1));
                distence[i+1][j] = dis+1;
            }
        }
        if(j>0)
        {
            if((distence[i][j-1] == 0 || distence[i][j-1] > dis+1) && maze[i][j-1] == '.')
            {
                next.pb(MKP(MKP(i,j-1), dis+1));
                distence[i][j-1] = dis+1;
            }
        }
        if(j+1<colum)
        {
            if((distence[i][j+1] == 0 || distence[i][j+1] > dis + 1) && maze[i][j+1] == '.')
            {
                next.pb(MKP(MKP(i,j+1), dis+1));
                distence[i][j+1] = dis+1;
            }
        }
    }
    return;
}
int movejoe(int i, int j)
{
    posible = true;
    queue< pair < pair < int ,int> , int> > next;
    next.pb(MKP(MKP(i,j), 1));
    int dis;
    while(!next.empty())
    {
        i = next.front().FT.FT;
        j = next.front().FT.SD;
        dis = next.front().SD;
        next.pop();
        if(i == 0 || j == 0 || i+1 == row || j+1 == colum)
        {
            return dis;
        }
        if(i>0)
        {
            if((distence[i-1][j] == 0 || distence[i-1][j] > dis+1) && maze[i-1][j] == '.')
            {
                next.pb(MKP(MKP(i-1,j), dis+1));
                distence[i-1][j] = dis+1;
                maze[i-1][j] = 'J';
            }
        }
        if(i+1<row)
        {
            if((distence[i+1][j] == 0 || distence[i+1][j] > dis+1) && maze[i+1][j] == '.')
            {
                next.pb(MKP(MKP(i+1,j), dis+1));
                distence[i+1][j] = dis+1;
                maze[i+1][j] = 'J';
            }
        }
        if(j>0)
        {
            if((distence[i][j-1] == 0 || distence[i][j-1] > dis+1) && maze[i][j-1] == '.')
            {
                next.pb(MKP(MKP(i,j-1), dis+1));
                distence[i][j-1] = dis+1;
                maze[i][j-1] = 'J';
            }
        }
        if(j+1<colum)
        {
            if((distence[i][j+1] == 0 || distence[i][j+1] > dis + 1) && maze[i][j+1] == '.')
            {
                next.pb(MKP(MKP(i,j+1), dis+1));
                distence[i][j+1] = dis+1;
                maze[i][j+1] = 'J';
            }
        }
    }
    posible = false;
    return 0;
}
