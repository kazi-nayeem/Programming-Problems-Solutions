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

#define MX 1000005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll m;
ll h1, a1, h2, a2;
ll xx1, yy1, xx2, yy2;

int dis[MX];

ll bfs(ll h, ll a, ll x, ll y)
{
    for(int i = 0; i <= m; i++) dis[i] = -1;
    dis[h] = 0;
    queue<ll> qu;
    qu.push(h);
    while(qu.size())
    {
        ll n = qu.front();
        qu.pop();
        ll v = ((n*x)%m+y)%m;
        if(dis[v] != -1) continue;
        dis[v] = dis[n]+1;
        qu.push(v);
    }
    return dis[a];
}

int main()
{
    scanf("%I64d", &m);
    scanf("%I64d %I64d", &h1, &a1);
    scanf("%I64d %I64d", &xx1, &yy1);
    scanf("%I64d %I64d", &h2, &a2);
    scanf("%I64d %I64d", &xx2, &yy2);
    ll c1 = bfs(h1,a1,xx1,yy1);
    ll c2 = bfs(h2,a2,xx2,yy2);
    if(c1 == -1 || c2 == -1)
    {
        puts("-1");
        return 0;
    }
    if(c1 == c2)
    {
        printf("%I64d\n", c1);
        return 0;
    }
    ll r1 = bfs((a1*xx1+yy1)%m,a1,xx1,yy1)+1;
    ll r2 = bfs((a2*xx2+yy2)%m,a2,xx2,yy2)+1;
    if(r1 == 0) r1 = -1;
    if(r2 == 0) r2 = -1;
    if(c1>c2 && r2 != -1 && (c1-c2)%r2 == 0)
    {
        printf("%I64d\n", c1);
        return 0;
    }
    if(c1<c2 && r1 != -1 && (c2-c1)%r1 == 0)
    {
        printf("%I64d\n", c2);
        return 0;
    }
    if(r1 == -1 || r2 == -1)
    {
        puts("-1");
        return 0;
    }
    int i = 1,flag = 1;
    for(i = 1; i < 1e7; i++)
    {
        if((c2-c1+i*r2)%r1 == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        puts("-1");
        return 0;
    }
    printf("%I64d\n", i*r2+c2);
    return 0;
}
