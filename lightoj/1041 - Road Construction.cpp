#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
using namespace std;

#define MX 52

struct edge{
    int u, v, w;

    bool operator < (const edge &p) const
    {
        return w<p.w;
    }
};

vector<edge> vc;
int parent[MX];
map<string, int> mp;

int mst(const int a);
int findpar(const int n);

int main()
{
    edge tem;
    int time, test, cm, l;
    char str1[MX], str2[MX];

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        vc.clear();
        mp.clear();
        cm = 0;
        scanf("%d", &l);

        for(int i = 0; i < l; i++)
        {
            scanf(" %s %s %d", str1, str2, &tem.w);

            if(mp.find(str1) == mp.end())
                mp[str1] = ++cm;
            if(mp.find(str2) == mp.end())
                mp[str2] = ++cm;

            tem.u = mp[str1];
            tem.v = mp[str2];

            vc.push_back(tem);
        }

        int di = mst(cm);

        if(di == -1)
            printf("Case %d: Impossible\n", test);
        else
            printf("Case %d: %d\n", test, di);
    }
    return 0;
}

int mst(const int a)
{
    for(int i = 0; i <= a; i++) parent[i] = i;
    sort(vc.begin(), vc.end());

    int u, v, total = 0, co = 1;
    int sz = vc.size();

    for(int i = 0; i < sz; i++)
    {
        u = findpar(vc[i].u);
        v = findpar(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            co++;
            total += vc[i].w;
            if(co == a) return total;
        }
    }
    return -1;
}


int findpar(const int n)
{
    if(parent[n] == n) return n;
    return parent[n] = findpar(parent[n]);
}

