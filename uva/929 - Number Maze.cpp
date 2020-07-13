#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

#define MX 1000

struct data{
    int i, j, w;
    bool operator < (const data& p) const
    {
        return p.w < w;
    }
    data(){}
    data(int a, int b, int c)
    {
        i = a;
        j = b;
        w = c;
    }
};

int arr[MX][MX];
char flag[MX][MX];
int callx[4] = {-1,1,0,0};
int cally[4] = {0,0,1,-1};

int dijkstra(const int x, const int y);

int main()
{
    int time, row, colum;
    scanf("%d", &time);

    while(time--)
    {
        scanf("%d %d", &row, &colum);

        for(int i = 0; i < row; i++)
            for(int j = 0; j < colum; j++)
            scanf("%d", &arr[i][j]);
        printf("%d\n", dijkstra(row-1,colum-1));
    }
    return 0;
}

int dijkstra(const int x, const int y)
{
    priority_queue<data> qu;
    int i, j, w, p, q;

    memset(flag, 0, sizeof flag);
    qu.push(data(0,0,arr[0][0]));

    while(!qu.empty())
    {
        i = qu.top().i;
        j = qu.top().j;
        w = qu.top().w;
        qu.pop();

        if(i == x && j == y) return w;

        if(flag[i][j] == 'v') continue;

        flag[i][j] = 'v';
        for(int k = 0; k < 4; k++)
        {
            p = i+callx[k];
            q = j+cally[k];
            if(p <0 || p>x || q < 0 || q > y) continue;

            qu.push(data(p,q,w+arr[p][q]));
        }
    }
}
