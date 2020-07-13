#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

struct data
{
    int arr[4];
    data() {}
    data(int a, int b, int c, int d)
    {
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
    }
    bool operator == (data& p) const
    {
        for(int i = 0; i < 4; i++)
            if(arr[i] != p.arr[i]) return false;
        return true;
    }
};

int w[8]= {1,-1};
int x[8] = {0,0,1,-1};
int y[8] = {0,0,0,0,1,-1};
int z[8] = {0,0,0,0,0,0,1,-1};

int dis[10][10][10][10];

int bfs(data st, data fi);

int main()
{
    //freopen("input.txt","r",stdin);
    int ti, s[4], f[4], n, wf,xf,yf,zf;
    scanf("%d", &ti);
    while(ti--)
    {
        memset(dis,-1,sizeof dis);
        for(int i = 0; i < 4; i++)
            scanf("%d", s+i);
        for(int i = 0; i < 4; i++)
            scanf("%d", f+i);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &wf, &xf, &yf, &zf);
            dis[wf][xf][yf][zf] = -2;
        }
        printf("%d\n", bfs(data(s[0],s[1],s[2],s[3]),data(f[0],f[1],f[2],f[3])));
    }
    return 0;
}

int bfs(data st, data fi)
{
    if(st == fi) return 0;
    queue<data> qu;
    int a, b, c, d, k;
    data tem;

    qu.push(st);
    dis[st.arr[0]][st.arr[1]][st.arr[2]][st.arr[3]] = 0;
    while(!qu.empty())
    {
        st = qu.front();
        qu.pop();

        k = dis[st.arr[0]][st.arr[1]][st.arr[2]][st.arr[3]];
        //printf("%d\n", k);
        for(int i = 0; i < 8; i++)
        {
            tem.arr[0] = (st.arr[0]+w[i]+10)%10;
            tem.arr[1] = (st.arr[1]+x[i]+10)%10;
            tem.arr[2] = (st.arr[2]+y[i]+10)%10;
            tem.arr[3] = (st.arr[3]+z[i]+10)%10;

            if(data(tem.arr[0],tem.arr[1],tem.arr[2],tem.arr[3]) == fi) return k+1;
            int & res = dis[tem.arr[0]][tem.arr[1]][tem.arr[2]][tem.arr[3]];
            if(res == -1)
            {
                qu.push(data(tem.arr[0],tem.arr[1],tem.arr[2],tem.arr[3]));
                res = k + 1;
            }
        }
    }
    return -1;
}
