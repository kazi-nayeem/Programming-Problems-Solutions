#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MX 105

struct edge{
    int u, v, w;

    bool operator < (const edge &p) const
    {
        return w<p.w;
    }
};

vector<edge> vc;
int parent[MX];

int mst(const int a, const int b);
int findpar(const int n);

int main()
{
    edge tem;
    int test = 0, c, s, q;

    while(scanf("%d %d %d", &c, &s, &q) == 3)
    {
        if(c == 0 && s == 0 && q == 0) break;

        if(test) putchar('\n');
        vc.clear();
        for(int i = 0; i < s; i++)
        {
            scanf("%d %d %d", &tem.u, &tem.v, &tem.w);
            vc.push_back(tem);
        }

        sort(vc.begin(), vc.end());
        int a, b;
        printf("Case #%d\n", ++test);

        for(int i = 0; i < q; i++)
        {
            scanf("%d %d", &a, &b);
            int di = mst(a, b);

            if(di == -1)
                printf("no path\n");
            else
                printf("%d\n", di);
        }
    }
    return 0;
}

int mst(const int a, const int b)
{
    for(int i = 0; i < MX; i++) parent[i] = i;

    int u, v, st, en;
    int sz = vc.size();

    for(int i = 0; i < sz; i++)
    {
        u = findpar(vc[i].u);
        v = findpar(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            st =findpar(a);
            en = findpar(b);
            if(st == en) return vc[i].w;
        }
    }
    return -1;
}


int findpar(const int n)
{
    if(parent[n] == n) return n;
    return parent[n] = findpar(parent[n]);
}
