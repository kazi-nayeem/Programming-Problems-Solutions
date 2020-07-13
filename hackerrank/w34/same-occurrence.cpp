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

#define MX 8005
#define inf 100000000

const ll mod = 1000000007ll;

int arr[MX];
vector<int> pos[MX];
map<int,int> mp;
int n, q;
map<pair<int,int>, ll > res;
map<int,int> cnt;

ll func(int x, int y)
{
    if(x>n && y > n)
    {
        return n*(n+1ll)/2ll;
    }
    if(res.find(make_pair(x,y)) != res.end()) return res[make_pair(x,y)];
    ll ans = 0;
    cnt.clear();
    int pre = 0;
    int sum = 0;
    int pos1 = 0, pos2 = 0;
    while(pos1<pos[x].size() || pos2 < pos[y].size())
    {
        int now, add;
        if(pos[x].size() == pos1)
        {
            now = pos[y][pos2];
            add = -1;
            pos2++;
        }
        else if(pos[y].size() == pos2)
        {
            now = pos[x][pos1];
            add = 1;
            pos1++;
        }
        else if(pos[x][pos1] < pos[y][pos2])
        {
            now = pos[x][pos1];
            add = 1;
            pos1++;
        }
        else
        {
            now = pos[y][pos2];
            add = -1;
            pos2++;
        }
        int len = now-pre;
        ans += len*(len-1)/2;
        ans += cnt[sum]*len;
        cnt[sum] += len;
        sum += add;
        pre = now;
        //printf("%lld\n", ans);
    }
    int now = n+1;
    int len = now-pre;
    ans += len*(len-1)/2;
    ans += cnt[sum]*len;
    res[make_pair(x,y)] = ans;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        if(mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]] = mp.size();
        }
        arr[i] = mp[arr[i]];
        pos[arr[i]].push_back(i);
    }

    for(int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(mp.find(x) == mp.end())
        {
            mp[x] = n+2;
        }
        if(mp.find(y) == mp.end())
        {
            mp[y] = n+2;
        }
        x = mp[x];
        y = mp[y];
        printf("%lld\n", func(min(x,y),max(x,y)));
    }

    return 0;
}


