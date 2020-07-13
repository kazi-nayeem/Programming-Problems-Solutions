#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;

#define MX 106

struct data{
    int age, hight, col;
};

vector<int> adj[MX/2];
int flag[MX], match[MX];
data arr[MX];

inline int absu(int a, int b)
{
    if(a>b) return a-b;
    return b-a;
}

bool Bipartite_Match(int n)
{
    int v, sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(flag[v] == 1) continue;
        flag[v] = 1;
        if(match[v] == -1 || Bipartite_Match(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}

int main()
{
    int te, ti, m, n, total;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &m, &n);
        for(int i = 0; i <= m; i++)
            adj[i].clear();
        for(int i = 1; i <=n+m; i++)
            scanf("%d%d%d", &arr[i].hight, &arr[i].age, &arr[i].col);
        for(int i = 1; i <= m; i++)
            for(int j = m+1; j <= m+n; j++)
        {
            if(arr[i].col == arr[j].col && (absu(arr[i].age,arr[j].age) <= 5) && (absu(arr[i].hight,arr[j].hight) <= 12))
            {
                adj[i].push_back(j);
            }
        }
        total=0;
        memset(match,-1,sizeof match);
        for(int i = 1; i <= m; i++)
        {
            memset(flag,0,sizeof flag);
            if(Bipartite_Match(i)) total++;
        }
        printf("Case %d: %d\n", te, total);
    }
    return 0;
}
