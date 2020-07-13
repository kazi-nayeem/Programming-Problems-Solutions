#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

#define MX 2005
#define MXC 11

struct edge{int u, v;
        int w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector<edge> vc;
int parent[MX];
map<string,int> mp;

int find_parent(int n)
{
    if(parent[n] == n) return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

int mst(int node)
{
    sort(vc.begin(),vc.end());

    for(int i = 1; i <= node; i++) parent[i] = i;

    int sz = (int) vc.size();
    int co = 0, total = 0;
    for(int i = 0; i < sz; i++)
    {
        int u = find_parent(vc[i].u);
        int v = find_parent(vc[i].v);

        if(u != v)
        {
            co++;
            parent[v] = u;
            total += vc[i].w;
            if(co+1 == node) return total;
        }
    }
    return total;
}

int main()
{
    int total, sat;
    edge temp;
    char str1[MXC], str2[MXC];
    int time;

    scanf("%d", &time);
    while(time--)
    {
        scanf("%d %d", &sat, &total);
        getchar();

        for(int i = 1; i <= sat; i++) parent[i] = i;
        mp.clear();
        int mc = 1;

        for(int i = 0; i < total; i++)
        {
            scanf("%s %s %d",str1, str2, &temp.w);
            getchar();

            if(mp.find(str1) == mp.end())
                mp[str1] = mc++;
            if(mp.find(str2) == mp.end())
                mp[str2] = mc++;

            temp.u = mp[str1];
            temp.v = mp[str2];

            vc.push_back(temp);
        }

        printf("%d\n", mst(sat));
        vc.clear();

        if(time) putchar('\n');

    }
    return 0;
}


