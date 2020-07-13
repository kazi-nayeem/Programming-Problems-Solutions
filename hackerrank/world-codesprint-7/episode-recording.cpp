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
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 10005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int n, te;
int start1[MX];
int start2[MX];
int end1[MX];
int end2[MX];
vector<int> adj[MX];
int flag[MX];

inline int first_node(int a)
{
    return a*2-1;
}

inline int second_node(int a)
{
    return a*2;
}

int func(int u, int low, int hi)
{
    if(u<low || u > hi) return 0;
    int & res = flag[u];
    if(res != -1) return res;
    res = 1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        res = max(res,func(adj[u][i],low,hi)+1);
    }
    return res;
}

bool check(int a, int b)
{
    int st = first_node(a);
    int en = second_node(b);
    memset(flag,-1,sizeof flag);
    for(int i = a; i <= b; i++)
    {
        //printf("%d\n", func(i,st,en));
        if(func(i,st,en) == b-a+1) return true;
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d %d %d", &start1[i], &end1[i], &start2[i], &end2[i]);
        }

        for(int i = 1; i <= n; i++)
        {
            adj[first_node(i)].clear();
            adj[second_node(i)].clear();
            for(int j = 1; j <= n; j++)
            {
                if(i == j) continue;
                if(end1[i]<start1[j])
                    adj[first_node(i)].push_back(first_node(j));
                if(end2[i]<start1[j])
                    adj[second_node(i)].push_back(first_node(j));

                if(end1[i]<start2[j])
                    adj[first_node(i)].push_back(second_node(j));
                if(end2[i]<start2[j])
                    adj[second_node(i)].push_back(second_node(j));
            }
        }
        /*for(int i = 1; i <= n*2; i++)
        {
            printf("%d-->", i);
            for(int j = 0; j < adj[i].size(); j++)
                printf("  %d", adj[i][j]);
            puts("");
        }*/
        int res = 1, a = 1;
        for(int i = 1; i+res <= n; i++)
        {
            for(int j = i+res; j <= n; j++)
            {
                if(!check(i,j)) continue;
                res = j-i+1;
                a = i;
            }
        }
        printf("%d %d\n", a, res+a-1);
    }
    return 0;
}


