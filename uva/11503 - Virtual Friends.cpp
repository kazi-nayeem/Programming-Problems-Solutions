#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

#define MX 100005
int parent[MX];

int find_friend(int fir, int sec, int nods);
int find_parent(int n);

int main()
{
    map<string,int> mp;
    int test;
    scanf("%d", &test);
    while(test--)
    {
        mp.clear();
        int edgs, mc = 1;
        scanf("%d", &edgs);
        getchar();

        char str1[25], str2[25];
        while(edgs--)
        {
            scanf("%s %s", str1, str2);

            if(mp.find(str1) == mp.end())
            {
                parent[mc] = mc;
                mp[str1] = mc++;
            }
            if(mp.find(str2) == mp.end())
            {
                parent[mc] = mc;
                mp[str2] = mc++;
            }

            printf("%d\n", find_friend(mp[str1], mp[str2], mc-1));
        }
    }
    return 0;
}

int find_friend(int fir, int sec, int nods)
{
    int u = find_parent(fir);
    int v = find_parent(sec);
    int total = 0;

    for(int i = 1; i <= nods; i++)
    {
        if(parent[i] == u)
            total++;
        else if(parent[i] == v)
        {
            total++;
            parent[i] = u;
        }
    }

    return total;
}

int find_parent(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}
