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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int pre[MX];

int func(vector<pii> arr, int t)
{
    sort(arr.begin(), arr.end());
    int pos = -1, mx = -inf;
    int ans = 0;
    for(int i = arr.size()-1; i>0; i--)
    {
        int p = arr[i].first;
        while(pos+1<i && arr[pos+1].first<=t-p)
        {
            pos++;
            mx = max(mx, arr[pos].second);
            pre[pos] = mx;
        }
        if(pos == -1) continue;
        if(pos<i)
        {
            ans = max(ans,arr[i].second+mx);
        }
        else
        {
            ans = max(ans,arr[i].second+pre[i-1]);
        }
    }
    return ans;
}

vector<pii> coin, dio;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, c, d;
    scanf("%d %d %d", &n, &c, &d);
    int dmx = -inf, cmx = -inf;
    for(int i = 1; i <= n; i++)
    {
        int b, p;
        char ch;
        scanf("%d %d %c", &b, &p, &ch);
        if(ch == 'C')
        {
            coin.push_back(make_pair(p,b));
            if(p<=c) cmx = max(cmx,b);
        }
        else
        {
            dio.push_back(make_pair(p,b));
            if(p<=d) dmx = max(dmx,b);
        }
    }
    int ans = max(0,cmx+dmx);
    ans = max(ans, func(coin,c));
    ans = max(ans, func(dio,d));
    printf("%d\n", ans);
    return 0;
}

