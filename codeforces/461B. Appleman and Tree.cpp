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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[MX];
vector<int> adj[MX];
ll dp[MX][2];

ll dfs(int n, int p, int f)
{
    if(adj[n].size() == 1)
    {
        if(adj[n][0] == p)
        {
            if(arr[n] == f) return 1;
            return 0;
        }
    }
    ll & res = dp[n][f];
    if(res != -1) return res;

    for(int i = 0; i < adj[n].size(); i++)
    {
        if(adj[n][i] == p) continue;
        res += dfs(adj[n][i], n, 1);
        if()
    }
}

int main()
{
    return 0;
}


