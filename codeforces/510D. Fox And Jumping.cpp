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

#define ll long long

int mx = 40000000;
int len[305];
int cost[305];
map<int,int> dp[305];

int rec(int pos, int g)
{
    if(g == 1) return 0;
    if(pos == 0) return mx;
    if(dp[pos].find(g) != dp[pos].end()) return dp[pos][g];
    dp[pos][g] = mx;
    dp[pos][g] = min(dp[pos][g],rec(pos-1,g));
    dp[pos][g] = min(dp[pos][g],(rec(pos-1,(__gcd(g,len[pos])))+cost[pos]));
    return dp[pos][g];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &len[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
        //puts("ok");
    int res = rec(n,0);
    if(res == mx) res = -1;
    printf("%d\n", res);
    return 0;
}
