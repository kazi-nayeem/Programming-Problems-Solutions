#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;

#define MX 10000

int indeg[MX];
vector<int> adj[MX];

int topsort(int n);

int main()
{
    //freopen("input.txt","r", stdin);
    char str1[15], str2[15];
    map<string,int> mp;
    int te, ti, edg, mpc;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        mp.clear();
        mpc = 0;
        //memset(indeg, 0, sizeof indeg);
        //for(int i = 0; i < MX; i++)
        // adj[i].clear();
        scanf("%d", &edg);
        for(int i = 0; i < edg; i++)
        {
            scanf(" %s %s", str1, str2);
            if(mp.find(str1) == mp.end())
            {
                mp[str1] = ++mpc;
                adj[mpc].clear();
                indeg[mpc] = 0;
            }
            if(mp.find(str2) == mp.end())
            {
                mp[str2] = ++mpc;
                adj[mpc].clear();
                indeg[mpc] = 0;
            }

            int to = mp[str2];
            indeg[to]++;
            adj[mp[str1]].push_back(to);
        }

        int k = topsort(mpc);
        if(k)
            printf("Case %d: Yes\n", te);
        else
            printf("Case %d: No\n", te);
    }
    return 0;
}

int topsort(int n)
{
    int total = 0;
    queue<int> qu;
    for(int i = 1; i <= n; i++)
        if(indeg[i] == 0) qu.push(i);

    while(!qu.empty())
    {
        int a = qu.front();
        qu.pop();

        total++;

        int sz = adj[a].size();
        for(int i = 0; i < sz; i++)
        {
            int b = adj[a][i];
            if(indeg[b] == 1)
                qu.push(b);
            else
                indeg[b]--;
        }
    }
    if(total == n) return 1;
    return 0;
}
