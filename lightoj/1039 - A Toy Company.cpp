#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct data{
    int a, b, c;
    data(){}
    data(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
};

int xx[8] = {0,0,0,0,1,-1};int yy[8] = {0,0,1,-1,0,0};
int zz[8] = {1,-1,0,0,0,0};

int flag[27][27][27];

int bfs(data str, data fini)
{
    //printf("%d %d %d %d %d %d\n", str.a, str.b, str.c, fini.a, fini.b, fini.c);
    if(flag[str.a][str.b][str.c] == -1) return -1;
    queue<data> qu;
    qu.push(str);
    data tem;
    int w, p, q, r;
    flag[str.a][str.b][str.c] = 0L;
    //printf(" %d ", flag[str.a][str.b][str.c]);
    while(!qu.empty())
    {
        tem = qu.front();
        qu.pop();
        w = flag[tem.a][tem.b][tem.c];
        //printf("%d %d %d %d %d\n", tem.a, tem.b, tem.c, w, flag[str.a][str.b][str.c]);
        if(tem.a == fini.a && tem.b == fini.b && tem.c == fini.c) return w;
        for(int i = 0; i < 6; i++)
        {
            p = (tem.a+xx[i]+26)%26;
            q = (tem.b+yy[i]+26)%26;
            r = (tem.c+zz[i]+26)%26;
            if(flag[p][q][r] <= w+1) continue;
            flag[p][q][r] = w+1;
            qu.push(data(p,q,r));
        }
    }
    return -1;
}

int main()
{
    char str1[100], str2[100], str3[100];
    char start[5], fini[5];
    int te, ti, n, len1, len2, len3;
    scanf(" %d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %s %s", start, fini);
        scanf(" %d", &n);
        for(int i = 0; i < 27; i++)
            for(int j = 0; j < 27; j++)
                for(int k = 0; k < 27; k++)
                    flag[i][j][k] = 1000000L;
        for(int l = 0; l < n; l++)
        {
            scanf(" %s %s %s", str1, str2, str3);
            len1 = strlen(str1);
            len2 = strlen(str2);
            len3 = strlen(str3);
            for(int i = 0; i < len1; i++)
                for(int j = 0; j < len2; j++)
                    for(int k = 0; k < len3; k++)
                        flag[str1[i]-'a'][str2[j]-'a'][str3[k]-'a'] = -1;
        }
        printf("Case %d: %d\n", te, bfs(data(start[0]-'a',start[1]-'a',start[2]-'a'), data(fini[0]-'a', fini[1]-'a', fini[2]-'a')));
    }
    return 0;
}
