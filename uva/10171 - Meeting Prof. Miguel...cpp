#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 290000
#define MX 30


int dis[2][MX][MX];
map<char,int> mp;
vector<char> vc;
char ch[MX];

void cle(void);
void floyd(int n);

int main()
{
    //freopen("input.txt", "r", stdin);
    int edge, w, k, s, e, mc;
    char str[25];
    while(scanf("%d", &edge) == 1)
    {
        if(edge == 0) return 0;
        getchar();
        cle();
        mc = 0;
        for(int i = 0; i < edge; i++)
        {
            gets(str);
            sscanf(str+8,"%d", &w);

            k = (str[0] == 'Y')? 0:1;

            if(mp.find(str[4]) == mp.end())
            {
                mp[str[4]] = ++mc;
                ch[mc] = str[4];
            }
            if(mp.find(str[6]) == mp.end())
            {
                mp[str[6]] = ++mc;
                ch[mc] = str[6];
            }
            s = mp[str[4]];
            e = mp[str[6]];
            if(dis[k][s][e] > w)
            dis[k][s][e] = w;
            if(str[2] == 'B'&& dis[k][e][s] > w)
                dis[k][e][s] = w;
        }

        gets(str);
        if(mp.find(str[0]) == mp.end())
        {
            mp[str[0]] = ++mc;
            ch[mc] = str[0];
        }
        if(mp.find(str[2]) == mp.end())
        {
            mp[str[2]] = ++mc;
            ch[mc] = str[2];
        }
        s = mp[str[0]];
        e = mp[str[2]];

        floyd(mc);
        w = INF;
        for(int i = 1; i <= mc; i++)
        {
            int m = dis[0][s][i]+dis[1][e][i];
            if(m < w)
            {
                vc.clear();
                vc.push_back(ch[i]);
                w = m;
            }
            else if(m == w)
                vc.push_back(ch[i]);
        }
        if(w == INF)
            printf("You will never meet.\n");
        else
        {
            printf("%d", w);
            sort(vc.begin(), vc.end());
            for(int i = 0; i < vc.size(); i++)
            {
                putchar(' ');
                putchar(vc[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}

void floyd(int n)
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
    {
        dis[0][i][j] = min(dis[0][i][j], dis[0][i][k]+dis[0][k][j]);
        dis[1][i][j] = min(dis[1][i][j], dis[1][i][k]+dis[1][k][j]);
    }
    return;
}

void cle(void)
{
    int k;
    memset(ch, 0, sizeof ch);
    mp.clear();
    for(int i = 0; i < MX; i++)
        for(int j = 0; j < MX; j++)
        {
            k = (i==j) ? 0:INF;
            dis[0][i][j] = k;
            dis[1][i][j] = k;
        }
    return;
}
