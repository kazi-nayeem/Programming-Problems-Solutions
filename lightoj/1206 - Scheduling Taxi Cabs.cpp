#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

#define MX 505

vector<int> adj[MX];

int flag[MX];
int match[MX];
int now, node;

bool bpm(int n)
{
    if(flag[n] == now) return false;
    flag[n] = now;
    for(int i = 0; i < adj[n].size(); i++)
    {
        int v = adj[n][i];
        if(match[v] == -1 || bpm(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}

int a[MX];
int b[MX];
int c[MX];
int d[MX];
int t[MX];

int main()
{
    int te, ti, h, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &node);
        memset(match,-1,sizeof match);
        for(int i = 0; i < node; i++)
        {
            scanf("%d:%d %d %d %d %d", &h, &m, &a[i], &b[i], &c[i], &d[i]);
            t[i] = h*60+m;
            adj[i].clear();
        }

        for(int i = 0; i < node; i++)
        {
            int cost = abs(a[i]-c[i])+abs(b[i]-d[i])+t[i];
            for(int j = 0; j < node; j++)
            {
                if(i == j) continue;
                int pass = abs(a[j]-c[i])+abs(b[j]-d[i])+cost;
                if(pass < t[j])
                    adj[i].push_back(j);
            }
        }
        int total = 0;
        for(int i = 0; i < node; i++)
        {
            now++;
            if(bpm(i)) total++;
        }
        printf("Case %d: %d\n", te, node-total);
    }
    return 0;
}
