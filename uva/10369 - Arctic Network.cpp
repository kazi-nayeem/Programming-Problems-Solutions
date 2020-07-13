#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

#define MX 505

struct edge{int u, v;
        double w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

struct point{double x, y;};

vector<edge> vc;
int parent[MX];

int find_parent(int n)
{
    if(parent[n] == n) return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

inline double squar(double x)
{
    return x*x;
}

double mst(int sat, int node)
{
    sort(vc.begin(),vc.end());

    for(int i = 1; i <= node; i++) parent[i] = i;

    int sz = (int) vc.size();
    int co = 0;
    for(int i = 0; i < sz; i++)
    {
        int u = find_parent(vc[i].u);
        int v = find_parent(vc[i].v);

        if(u != v)
        {
            co++;
            parent[v] = u;
            if(co+sat == node) return vc[i].w;
        }
    }
    return 0;
}

int main()
{
    int time;
    scanf("%d", &time);

    point coordi[MX];
    int total, sat;
    edge temp;

    while(time--)
    {
        scanf("%d %d", &sat, &total);

        for(int i = 1; i <= total; i++)
        {
            scanf("%lf %lf", &coordi[i].x, &coordi[i].y);

            for(int j = 1; j < i; j++)
            {
                temp.u = i;
                temp.v = j;
                temp.w = (double) sqrt(squar(coordi[i].x - coordi[j].x)+ squar(coordi[i].y - coordi[j].y));

                vc.push_back(temp);
            }
        }

        printf("%.2lf\n", mst(sat, total));
        vc.clear();

    }
    return 0;
}

