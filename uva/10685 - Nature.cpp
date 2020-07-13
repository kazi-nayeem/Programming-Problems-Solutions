#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
using namespace std;

#define MX 5005
int parent[MX];
bool flag[MX];

void union_parent(int node);
int max_parent(int node);
void makeset(int node);
int parent_find(int n);

int main()
{
    map<string,int> mp;
    int node, edgs;
    while(scanf("%d %d", &node, &edgs) == 2)
    {
        getchar();
        if(node == 0 && edgs == 0) return 0;
        makeset(node);
        int mc = 1;
        char str1[35], str2[35];
        for(int i = 0; i < node; i++)
        {
            gets(str1);
            mp[str1] = mc++;
        }
        for(int i = 0; i < edgs; i++)
        {
            scanf("%s %s", str1, str2);
            int u = parent_find(mp[str1]);
            int v = parent_find(mp[str2]);
            if(u != v)
                parent[u] = v;
        }
        printf("%d\n", max_parent(node));
    }
}

int max_parent(int node)
{
    union_parent(node);
    int maxi = 0, total;
    for(int i = 1; i <= node; i++)
    {
        if(flag[i] == false)
        {
            total = 1;
            for(int j = i + 1; j <= node; j++)
            {
                if(parent[i] == parent[j])
                {
                    total++;
                    flag[j] = true;
                }
            }
            if(maxi < total)
                maxi = total;
        }
    }
    return maxi;
}

int parent_find(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = parent_find(parent[n]);
}

void makeset(int node)
{
    for(int i = 1; i <= node; i++)
    {
        parent[i] = i;
        flag[i] = false;
    }
    return;
}

void union_parent(int node)
{
    for(int i = 1; i <= node; i++)
        parent[i] = parent_find(parent[i]);
}
