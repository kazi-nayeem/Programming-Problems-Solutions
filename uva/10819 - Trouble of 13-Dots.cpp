//C headers
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>

//C++ headers
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

#define MX 10505
#define INF 1000

int dp[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    int m, n;
    while(scanf("%d%d", &m, &n) == 2)
    {
        int k = m;
        if(m >= 1800) m += 200;
        memset(dp,0,sizeof dp);
        int p, v;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &p, &v);
            for(int j = m; j >= p; j--)
                dp[j] = max(dp[j], dp[j-p]+v);
        }
        p = 0;
        for(int i = 0; i <= m; i++)
        {
            if(p < dp[i] && ( i < k ||(i>2000)))
            {
                p = dp[i];
                printf("%d\n", i);
            }
        }
        printf("%d\n", p);
    }
    return 0;
}

