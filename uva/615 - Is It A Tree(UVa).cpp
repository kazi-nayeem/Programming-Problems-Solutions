#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

#define MX 100000

map<int,int> mp;
int flag[MX];
int par[MX];

int find_par(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_par(par[a]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int u, v, te = 1, mpc;

    while(scanf("%d%d", &u, &v) == 2)
    {
        if(u < 0 && v < 0) return 0;
        if(u == 0 && v == 0)
        {
            printf("Case %d is a tree.\n", te++);
            continue;
        }
        memset(flag, 0, sizeof flag);
        for(int i = 0; i < MX; i++)
            par[i] = i;
        mpc = 2;
        mp.clear();
        mp[u] = 1;
        if(v != u)
        {
            mp[v] = 2;
            mpc++;
            flag[2] = 1;
            par[2] = 1;
        }
        else
            flag[1] = 5;
        while(scanf("%d%d", &u, &v) == 2)
        {
            if(u == 0 && v == 0) break;
            if(mp.find(u) == mp.end())
                mp[u] = mpc++;
            if(mp.find(v) == mp.end())
                mp[v] = mpc++;
            u = mp[u];
            v = mp[v];
            flag[v]++;
            if(u == v) flag[u]++;
            u = find_par(u);
            v = find_par(v);
            if(u != v) par[u] = v;
        }
        int tree = 1, zero = 0;
        int x = find_par(1);
        for(int i = 1; i < mpc; i++)
        {
            if(x != find_par(i))
            {
                tree = 0;
                break;
            }
            if(flag[i] > 1) {
                tree = 0;
                break;
            }
            if(flag[i] == 0) zero++;
            if(zero > 1)
            {
                tree = 0;
                break;
            }
        }
        if(tree && zero == 1) printf("Case %d is a tree.\n", te++);
        else printf("Case %d is not a tree.\n", te++);
    }
    return 0;
}
