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

#define MX 272144
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct data
{
    int v, cnt;
    data(int val, int cn)
    {
        v = val;
        cnt = cn;
    }
    bool operator < (const data & p) const
    {
        if(cnt != p.cnt) return cnt>p.cnt;
        return v<p.v;
    }
};

int res[MX];
bool flag[MX];
int arr[MX];
map<int,int> mp;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, a;
    scanf("%d", &n);
    for(int i = 1; i < 2*n; i++)
    {
        scanf("%d", &a);
        if(mp.find(a) == mp.end())
        {
            mp[a] = 0;
            arr[mp.size()] = a;
        }
        mp[a]++;
    }
    if(mp.size() != n)
    {
        printf("NO");
        return 0;
    }
    priority_queue<data> qu;
    for(int i = 1; i <= n; i++)
    {
        //printf("%d %d\n", arr[i], mp[arr[i]]);
        qu.push(data(arr[i],mp[arr[i]]));
    }
    bool posi = true;
    for(int i = 2*n-1; i > 0; i--)
    {
        if(flag[i]) continue;
        if(qu.empty())
        {
            posi = false;
            break;
        }
        data now = qu.top();
        qu.pop();
        int j = i;
        while(j>=1)
        {
            flag[j] = true;
            res[j] = now.v;
            now.cnt--;
            j = j/2;
        }
        if(now.cnt != 0)
        {
            //printf(">>>%d %d %d\n", i, now.v, now.cnt);
            posi = false;
            break;
        }
    }
    if(!posi)
    {
        printf("NO");
        return 0;
    }
    for(int i = 1; i < n; i++)
    {
        if(min(res[i*2],res[i*2+1]) != res[i])
        {
            posi = false;
            break;
        }
    }

    if(!posi)
    {
        printf("NO");
        return 0;
    }
    mp.clear();
    for(int i = n; i < 2*n; i++)
    {
        mp[res[i]] = 1;
    }

    if(mp.size() != n)
    {
        printf("NO");
        return 0;
    }

    printf("YES\n%d", res[1]);
    for(int i = 2; i < 2*n; i++)
        printf(" %d", res[i]);
    puts("");
    return 0;
}


