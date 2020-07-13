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
using namespace std;

#define ll long long
#define MX 100005

int oder[MX];
int pos[MX];


int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int now, pre;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &oder[i]);
        pos[oder[i]] = i;
    }
    int x;
    ll total = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        now = pos[x];
        if(pos[x] == 1) continue;
        total += (ll) (now-1)/k;
        pos[x]--;
        pos[oder[now-1]] = now;
        oder[now] = oder[now-1];
        oder[now-1] = x;
    }
    printf("%I64d\n", total+m);
    return 0;
}

