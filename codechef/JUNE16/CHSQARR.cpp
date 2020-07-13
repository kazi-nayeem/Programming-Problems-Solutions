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

#define MX 1005
#define inf 1500000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int arr[MX][MX];
int sum[MX][MX];
int maxi[MX][MX];

struct data
{
    int v,pos;
    data(int a, int b)
    {
        v = a;
        pos = b;
    }
    bool operator < (const data & p) const
    {
        return v < p.v;
    }
};

deque<data> qu;

void intiqu()
{
    while(!qu.empty()) qu.pop_back();
}

void add(data a)
{
    while(!qu.empty() && qu.back().v <= a.v) qu.pop_back();
    qu.push_back(a);
}

data gettop(int n, int mi)
{
    while(qu.front().pos <= n-mi) qu.pop_front();
    return qu.front();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*intiqu();
    int ca = 1, r, x;
    scanf("%d", &r);
    while(scanf("%d", &x) == 1)
    {
        add(data(x,ca));
        printf("%d %d\n", gettop(ca,r).v, gettop(ca,r).pos);
        ca++;
    }

    return 0;*/
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i][j-1]+arr[i][j];
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            sum[i][j] += sum[i-1][j];
        }
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%d ", sum[i][j]);
        }
        puts("");
    }*/
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        for(int i = 1; i <= n; i++)
        {
            intiqu();
            for(int j = 1; j < c; j++) add(data(arr[i][j],j));
            for(int j = c; j <= m; j++)
            {
                //printf("%d %d\n", i, j);
                add(data(arr[i][j],j));
                //while(qu.top().pos <= j-c) qu.pop();
                maxi[i][j] = gettop(j,c).v;
            }
        }

        int res = inf;
        for(int j = c; j <= m; j++)
        {
            //priority_queue<data> qu;]
            intiqu();
            for(int i = 1; i < r; i++) add(data(maxi[i][j],i));
            for(int i = r; i <= n; i++)
            {
                //printf("%d %d\n", i, j);
                add(data(maxi[i][j],i));
                //while(qu.top().pos <= i-r) qu.pop();
                //printf("%d %d %d\n", qu.top().v*r*c - (sum[i][j]-sum[i-r][j]-sum[i][j-c]+sum[i-r][j-c]), i, j);
                res = min(res,gettop(i,r).v*r*c - (sum[i][j]-sum[i-r][j]-sum[i][j-c]+sum[i-r][j-c]));
            }
        }
        printf("%d\n", res);
        /*for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                printf("%d ", maxi[i][j]);
            }
            puts("");
        }*/
    }
    return 0;
}



