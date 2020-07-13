#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

#define ll long long int
#define MX 50050


ll dp[MX];
int arr[105];

int main()
{
    int te, ti, n, total, div, p, mx;
    ll tem;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        memset(dp,0,sizeof dp);
        total = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf(" %d", &arr[i]);
            total += arr[i];
        }
        div = total>>1;
        dp[0] = 1LL;
        for(int i = 1; i <= n; i++)
            for(int j = div; j >= arr[i]; j--)
                dp[j] = (ll) dp[j] | ((ll)dp[j-arr[i]]<<1);
        p = n>>1;
        if(n%2 == 0)
        {
            for(int i = div; i >= 0; i--)
            {
                if(((ll)(dp[i]>>p)&1LL) == 1LL)
                {
                    mx = i;
                    break;
                }
            }
        }
        else
        {
            for(int i = div; i >= 0; i--)
            {
                tem = (ll)dp[i]>>p;
                if((((ll)tem&1LL) == 1LL) || (((ll)tem&2LL) == 2LL))
                {
                    mx = i;
                    break;
                }
            }
        }
        printf("Case %d: %d %d\n", te, mx, total - mx);
    }
    return 0;
}
