#include<cstdio>
#include<iostream>
using namespace std;

#define MX 255
#define INF 500000000

struct data{int w, t;

    data(){}

    data(int a, int b)
    {
        w = a;
        t = b;
    }

    bool operator < (const data& p) const
    {
        if(t != p.t) return t < p.t;
        return w < p.w;
    }

    data operator + (const data& p) const
    {
        data temp;
        temp.w = w + p.w;
        temp.t = t + p.t;
        return temp;
    }
};

data arr[MX][MX];

void  floyd(int n);
void cle(int n);

int main()
{
    int ti, x, y;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &x, &y);
        cle(x);
        for(int i = 0; i < y; i++)
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            data tem;
            tem = data(c, d);
            if(tem < arr[a][b])
            {
                arr[a][b] = tem;
                arr[b][a] = tem;
            }
        }
        floyd(x);
        scanf("%d", &y);
        for(int i = 0; i < y; i++)
        {
            int s, e;
            scanf("%d %d", &s, &e);
            if(arr[s][e].t == INF)
            {
                printf("No Path.\n");
            }
            else
                printf("Distance and time to reach destination is %d & %d.\n", arr[s][e].t, arr[s][e].w);
        }
        if(ti) putchar('\n');
    }
    return 0;
}

void  floyd(int n)
{
    data tem;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
    {
        tem.t = arr[i][k].t + arr[k][j].t;
        tem.w = arr[i][k].w + arr[k][j].w;
        if(tem < arr[i][j])
            arr[i][j] = tem;
    }
    return;
}
void cle(int n)
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
    {
        arr[i][j].t = (i == j)? 0 : INF;
        arr[i][j].w = (i == j)? 0 : INF;
    }
    return;
}
