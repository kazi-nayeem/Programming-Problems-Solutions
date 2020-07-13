#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

#define MX 100005
#define inf 2139062143

vector<int> adj[MX];
int lis[MX], arr[MX], res[MX], n, m, q;

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        memset(lis,127,sizeof lis);
        for(int i = 0; i < MX; i++) adj[i].clear();
        lis[0] = -inf;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", arr+i);
            int pos = lower_bound(lis,lis+i,arr[i])-lis;
            adj[pos].push_back(i);
            lis[pos] = arr[i];
        }
        printf("Case %d:\n", te);
        while(q--)
        {
            scanf("%d", &m);
            if(adj[m].size() == 0)
            {
                puts("Impossible");
                continue;
            }
            int k = m;
            res[m] = adj[m][0];
            while(m--)
            {
                for(int i = 0; i < adj[m].size(); i++)
                    if(arr[res[m+1]] > arr[adj[m][i]])
                    {
                        res[m] = adj[m][i];
                        break;
                    }
            }
            for(int i = 1; i < k; i++)
                printf("%d ", arr[res[i]]);
            printf("%d\n", arr[res[k]]);
        }
    }
    return 0;
}
