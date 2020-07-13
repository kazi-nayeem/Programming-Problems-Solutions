#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define MX 3005
#define ll long long

set<int> s;
vector<int> adj[MX];
int flag[MX];

int main()
{
    vector<int> vc;
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    ll int res = 0;
    for(int i = 1; i <= n; i++)
    {
        s.clear();
        memset(flag,0,sizeof flag);
        int sz1 = adj[i].size();
        for(int j = 0; j < sz1; j++)
        {
            v = adj[i][j];
            int sz2 = adj[v].size();
            for(int k = 0; k < sz2; k++)
            {
                flag[adj[v][k]]++;
                s.insert(adj[v][k]);
            }
        }
        sz1 = s.size();
        for (std::set<int>::iterator it=s.begin(); it!=s.end(); ++it) // copy from www.cplusplus.com
        {
            if(*it == i) continue;
            res += (ll) flag[ *it ]*(flag[*it]-1)/2;
        }
    }
    printf("%I64d\n", res);
    return 0;
}
