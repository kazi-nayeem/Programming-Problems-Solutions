#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> adj[1001];

int main()
{
    int te, ti, x, n, q, u, v, mx;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        for(int i = 0; i <= 1000; i++) adj[i].clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            adj[x].push_back(i);
        }
        printf("Case %d:\n", te);
        while(q--)
        {
            scanf("%d%d", &u, &v);
            int pos = -1;
            int mx = 10000;
            for(int i = 1; i <= 1000 && mx > 0; i++)
            {
                if(adj[i].empty()) continue;
                int li = lower_bound(adj[i].begin(), adj[i].end(),u)-adj[i].begin();
                int tk = 0;
                while(adj[i].size() > li && adj[i][li] <= v && tk < 2)
                {
                    li++;
                    tk++;
                }
                if(tk == 0) continue;
                if(tk > 1)
                {
                    mx = 0;
                    break;
                }
                if(pos == -1)
                {
                    pos = i;
                    continue;
                }
                if(i-pos < mx) mx = i-pos;
                pos = i;
            }
            printf("%d\n", mx);
        }
    }
    return 0;
}
