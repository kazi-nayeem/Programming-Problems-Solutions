//#include <bits/stdc++.h>

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
#include<map>
using namespace std;

#define MX 200005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int point(char a)
{
    if(a>='0' && a<='9') return a-'0'+52;
    if(a>='A' && a<='Z') return a-'A'+26;
    return a-'a';
}

char get(int a)
{
    if(a < 26) return a+'a';
    if(a < 52) return a-26+'A';
    return a-52+'0';
}

int node(char a, char b)
{
    a = point(a);
    b = point(b);
    return (a)*62+(b);
}

int path[MX], pos;
int indeg[62*62];
int outdeg[62*62];
int comp[62*62];
vector<int> adj[MX];

void dfs(int n)
{
    for(; comp[n] < adj[n].size();)
    {
        comp[n]++;
        dfs(adj[n][comp[n]-1]);
    }
    path[pos++] = n;
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[5];
    for(int i = 0; i < n; i++)
    {
        scanf(" %s", str);
        int u = node(str[0],str[1]);
        int v = node(str[1],str[2]);
        indeg[v]++;
        outdeg[u]++;
        adj[u].push_back(v);
    }
    int start = 0;
    bool flag = true;
    int cont = 0;
    for(int i = 0; i < 62*62; i++)
    {
        if(1 > outdeg[start] && outdeg[i] > 0) start = i;
        if(indeg[i] == outdeg[i]) continue;
        if(abs(indeg[i]-outdeg[i]) > 1)
        {
            flag = false;
            break;
        }
        cont++;
        if(indeg[i] < outdeg[i]) start = i;
    }
    if(!flag || cont>2)
    {
        puts("NO");
        return 0;
    }
    pos = 0;
    //printf("%d\n", start);
    dfs(start);
    if(pos < n)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i = pos-1; i >= 0; i--)
        putchar(get(path[i]/62));
    putchar(get(path[0]%62));
    puts("");
    return 0;
}
