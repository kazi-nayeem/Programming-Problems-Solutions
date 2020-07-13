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

int deg[MX];
vector<int> adj[MX];

void func(int k, int a)
{
    for(int i = a+1; i <=a+k+1; i++) deg[i] = k-1;
    for(int i = a+2; i<=a+k+1; i++) adj[a+k+2].push_back(i);
    for(int i = a+k+1; i > a; i--)
    {
        int p = 1+a;
        while(deg[i]>0)
        {
            while(deg[p] == 0)
            {
                p++;
            }
            adj[i].push_back(p);
            deg[p]--;
            deg[i]--;
            p++;
        }
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    if(k%2 == 0){
        puts("NO");
        return 0;
    }
    puts("Yes");
    if(k == 1)
    {
        puts("2 1\n1 2");
        return 0;
    }
    func(k,0);
    func(k,k+2);
    adj[k+3].push_back(1);
    int sz = 0;
    for(int i = 1; i <= (2*(k+2)); i++)
        sz += adj[i].size();
    printf("%d %d\n", (2*(k+2)), sz);
    for(int i = 1; i <= (2*(k+2)); i++)
        for(int j = 0; j < adj[i].size(); j++)
            printf("%d %d\n", adj[i][j], i);
    return 0;
}


