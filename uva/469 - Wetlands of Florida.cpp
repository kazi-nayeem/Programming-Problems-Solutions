#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

char florida[101][102];
short int flag[101][102];
int row, colum;


int bfs(int i, int j);

int main()
{
    int time;
    char temp[102];
    scanf("%d", &time);
    getchar();
    getchar();
    while(time--)
    {
        int i = 1;
        gets(florida[0]);
        colum = strlen(florida[0]);
        while(gets(florida[i]))
        {
            if(florida[i][0] != 'L' && florida[i][0] != 'W') break;
            i++;
        }
        row = i;
        int x, y;
        sscanf(florida[i], "%d %d", &x, &y);
        printf("%d\n", bfs(x-1,y-1));
        while(gets(temp))
        {
            if(strlen(temp) == 0) break;
            sscanf(temp,"%d %d", &x, &y);
            printf("%d\n", bfs(x-1,y-1));
        }
        if(time)
            putchar('\n');
    }
    return 0;
}

int bfs(int i, int j)
{
    memset(flag,0,sizeof flag);
    queue<pair<int,int> > next;
    int x,y;
    int total = 0;
    next.push(make_pair(i,j));
    while(!next.empty())
    {
        x = next.front().first;
        y = next.front().second;
        next.pop();
        flag[x][y] = 1;
        if(florida[x][y] == 'W')
        {
            total++;
            if(x>0)
            {
                if(y>0)
                {
                    if(flag[x-1][y-1] == 0)
                    {
                        next.push(make_pair(x-1,y-1));
                        flag[x-1][y-1] = 1;
                    }
                }
                if(flag[x-1][y] == 0)
                {
                    next.push(make_pair(x-1,y));
                    flag[x-1][y] = 1;
                }
                if(y + 1 < colum)
                {
                    if(flag[x-1][y+1] == 0)
                    {
                        next.push(make_pair(x-1,y+1));
                        flag[x-1][y+1] = 1;
                    }
                }
            }
            if(x+1<colum)
            {
                if(y>0)
                {
                    if(flag[x+1][y-1] == 0)
                    {
                        next.push(make_pair(x+1,y-1));
                        flag[x+1][y-1] = 1;
                    }
                }
                if(flag[x+1][y] == 0)
                {
                    next.push(make_pair(x+1,y));
                    flag[x+1][y] = 1;
                }
                if(y + 1< colum)
                {
                    {
                        if(flag[x+1][y+1] == 0)
                            next.push(make_pair(x+1,y+1));
                        flag[x+1][y+1] = 1;
                    }
                }
            }
            if(y>0)
            {
                if(flag[x][y-1] == 0)
                {
                    next.push(make_pair(x,y-1));
                    flag[x][y-1] = 1;
                }
            }
            if(y + 1< colum)
            {
                if(flag[x][y+1] == 0)
                {
                    next.push(make_pair(x,y+1));
                    flag[x][y+1] = 1;
                }
            }
        }
    }
    return total;
}
