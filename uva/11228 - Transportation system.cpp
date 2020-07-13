#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

#define MX 1005

struct point {int x, y;};
struct edge {  int u, v;
        double w;
        bool operator <(const edge& p) const
        {
            return w < p.w;
        }
};

vector<edge> next;
int parent[MX];
int state, road, rail, maxi;

int input(void);
void mst(const int node);
int statef(const int n);
int find_parent(int n);

inline int squar(int n)
{
    return n * n;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int time, test, bindo;
    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        bindo = input();
        mst(bindo);
        printf("Case #%d: %d %d %d\n", test, state, road, rail);
    }
    return 0;
}

int input(void)
{
    int node;
    edge finding;
    point temp[MX];
    scanf("%d %d", &node, &maxi);

    next.clear();
    for(int i = 0; i < node; i++) parent[i] = i;

    for(int i = 0; i < node; i++)
    {
        scanf("%d %d", &temp[i].x, &temp[i].y);

        for(int j = 0; j < i; j++)
        {
            finding.u = i;
            finding.v = j;
            finding.w = sqrt(squar(temp[i].x - temp[j].x)+squar(temp[i].y-temp[j].y));

            next.push_back(finding);
        }
    }
    return node;
}

void mst(const int node)
{
    int add = 0, u, v, i;
    sort(next.begin(), next.end());
    int sz = next.size();

    double total = 0;

    for(i = 0; i < sz; i++)
    {
        if(next[i].w > maxi) break;

        u = find_parent(next[i].u);
        v = find_parent(next[i].v);

        if(u != v)
        {
            parent[u] = v;
            total += next[i].w;
            add++;
        }
    }

    if(total - (int)total < 0.5)
        road = (int) total;
    else
        road = (int) total + 1;
    state = statef(node);
    total = 0;

    for(;i < sz; i++)
    {
        u = find_parent(next[i].u);
        v = find_parent(next[i].v);

        if(u != v)
        {
            parent[u] = v;
            add++;
            total += next[i].w;
        }
        if(add+1==node) break;
    }
    if(total - (int)total < 0.5)
        rail = (int) total;
    else
        rail = (int) total + 1;

    return;
}

int statef(const int n)
{
    set<int> st;
    for(int i = 0; i < n; i++)
        st.insert(find_parent(i));
    return (int) st.size();
}

int find_parent(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}
