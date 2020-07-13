#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

struct data{int v, dis, cost;
};

data arr[35];
int dp[1005];
vector<int> use[1005];

int main()
{
    int t, w, gold;
    bool flag = false;
    while(scanf("%d %d %d", &t, &w, &gold) == 3)
    {
        if(flag) putchar('\n');
        flag = true;
        for(int i = 0; i <= t; i++)
        {
            use[i].clear();
            dp[i] = -1;
        }
        dp[0] = 0;
        for(int i = 0; i < gold; i++)
        {
            scanf("%d %d", &arr[i].dis, &arr[i].v);
            arr[i].cost = arr[i].dis * w * 3;
        }
        int maxi = 0, k;
        for(int i = 0; i < gold; i++)
        {
            k = arr[i].cost;
            maxi = min(maxi+k, t);
            for(int j = maxi; j >= k; j--)
            {
                if(dp[j-k] == -1) continue;
                if(dp[j-k]+arr[i].v > dp[j])
                {
                    dp[j] = dp[j-k]+arr[i].v;
                    use[j].clear();
                    use[j] = use[j-k];
                    use[j].push_back(i);
                }
            }
        }
        int m = 0;
        for(int i = 1; i <= t; i++)
            if(dp[i] > dp[m])
                m = i;
        int sz = use[m].size();
        printf("%d\n%d\n", dp[m],sz);
        for(int i = 0; i < sz; i++)
            printf("%d %d\n", arr[use[m][i]].dis, arr[use[m][i]].v);
    }
    return 0;
}
