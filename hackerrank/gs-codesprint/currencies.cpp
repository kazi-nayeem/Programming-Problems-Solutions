#include <bits/stdc++.h>

using namespace std;

typedef pair<double,long long> pll;
typedef long long ll;
const ll mod = 1000000007;

ll bigmod(ll a, ll p)
{
    if(p == 0) return 1;
    ll m = bigmod(a,p/2);
    m =  (m*m)%mod;
    if(p%2) m = (m*a)%mod;
    return m;
}

pll arr[100][100];
pll dp[25][25][25];

long long currencies(int n, int x, int s, int f, int m, vector < vector<int> > A)
{
    // Complete this function
    //printf("%d %d %d %d %d\n", n, x, s, f, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                arr[i][j].first = -1.0e16;
            else
                arr[i][j].first = log((double) A[i][j]);
            arr[i][j].second =  A[i][j];
            //printf("%d %f\n", A[i][j], arr[i][j].first);
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                dp[i][j][0] = make_pair(0.0,1ll);
            else
                dp[i][j][0] = make_pair(-1.0e16,0ll);
        }
    for(int k = 1; k <= n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                dp[i][j][k] = make_pair(-1.0e16,0ll);
                for(int l = 0; l < n; l++)
                {
                    if(dp[i][j][k].first<dp[i][l][k-1].first+arr[l][j].first)
                    {
                        dp[i][j][k].first = dp[i][l][k-1].first+arr[l][j].first;
                        dp[i][j][k].second = (dp[i][l][k-1].second*arr[l][j].second)%mod;
                    }
                }
            }
    pll ans = make_pair(-1.0e16,0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= min(n,m); j++)
        {
            for(int k = 0; k <= min(n,m-j); k++)
            {
                if(j+k == m)
                {
                    pll tem = dp[s][i][j];
                    tem.first += dp[i][f][k].first;
                    tem.second *= dp[i][f][k].second;
                    tem.second %= mod;
                    if(tem.first>ans.first)
                    {
                        ans = tem;
                        //printf("%d %d %d %lld %lld %lld\n", i, j, k, ans.second, dp[s][i][j].second);
                    }
                    continue;
                }
                for(int l = 2; l <= n; l++)
                {
                    if((m-j-k)%l) continue;
                    pll tem = dp[s][i][j];
                    tem.first += dp[i][f][k].first;
                    tem.second *= dp[i][f][k].second;
                    tem.second %= mod;
                    tem.first += dp[i][i][l].first*(m-j-k)/l;
                    tem.second *= bigmod(dp[i][i][l].second,(m-j-k)/l);
                    tem.second %= mod;
                    if(tem.first>ans.first)
                    {
                        ans = tem;
                    }
                }
            }
        }
    }
    return (ans.second*x)%mod;
}

int main()
{
    int n;
    cin >> n;
    int x;
    int s;
    int f;
    int m;
    cin >> x >> s >> f >> m;
    vector< vector<int> > A(n,vector<int>(n));
    for(int A_i = 0; A_i < n; A_i++)
    {
        for(int A_j = 0; A_j < n; A_j++)
        {
            cin >> A[A_i][A_j];
        }
    }
    printf("%lld\n", currencies(n, x, s, f, m, A));
    return 0;
}
