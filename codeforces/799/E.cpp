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

vector<int> one, two, both, none;

ll arr[MX];
int flag1[MX];
int flag2[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    int p, x;
    scanf("%d", &p);
    while(p--)
    {
        scanf("%d", &x);
        flag1[x] = 1;
    }
    scanf("%d", &p);
    while(p--)
    {
        scanf("%d", &x);
        flag2[x] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(flag1[i] == 1 && flag2[i] == 1)
            both.push_back(arr[i]);
        else if(flag1[i] == 1 && flag2[i] == 0)
            one.push_back(arr[i]);
        else if(flag1[i] == 0 && flag2[i] == 0)
            none.push_back(arr[i]);
        else
            two.push_back(arr[i]);
    }
    sort(both.begin(),both.end());
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    stack<ll> st[3];
    ll total = 0;
    for(int i = 0; i < k && i < one.size(); i++)
    {
        total += one[i];
        st[0].push(one[i]);
    }
    for(int i = 0; i < k && i < two.size(); i++)
    {
        total += two[i];
        st[1].push(two[i]);
    }
    for(int i = k; i < one.size(); i++)
        none.push_back(one[i]);
    for(int i = k; i < two.size(); i++)
        none.push_back(two[i]);
    sort(none.begin(), none.end());
    for(int i = 0; i < none.size() && ((st[0].size()+st[1].size()+st[2].size()) < m); i++)
    {
        total += none[i];
        st[2].push(none[i]);
    }
    queue<ll> extra;
    for(int i = st[2].size(); i < none.size(); i++)
    {
        extra.push(none[i]);
    }
    int len[3];
    len[0] = k;
    len[1] = k;
    len[2] = 0;
    ll ans = mod*mod;
    if(st[0].size()>=k && st[1].size() >= k && ((st[0].size()+st[1].size()+st[2].size()) == m))
    {
        ans = min(ans,total);
    }
    //printf("%d %d %d %d\n", st[0].size(), st[1].size(), st[2].size(), both.size());
    for(int i = 1; i <= both.size() && i <= m; i++)
    {
        total += both[i-1];
        while(((st[0].size()+st[1].size()+st[2].size()+i) > m))
        {
            int pos = -1, cost = 0;
            for(int j = 0; j < 3; j++)
            {
                if(st[j].empty()) continue;
                if(st[j].size()+i<=len[j]) continue;
                if(st[j].top()>cost)
                {
                    pos = j;
                    cost = st[j].top();
                }
            }
            if(pos == -1) break;
            st[pos].pop();
            total -= cost;
        }
        while((!extra.empty()) && (!st[0].empty()) && (st[0].size()+i>k) && (st[0].top()>extra.front()))
        {
            total -= st[0].top();
            st[0].pop();
            total += extra.front();
            st[2].push(extra.front());
            extra.pop();
        }
        while((!extra.empty()) && (!st[1].empty()) && (st[1].size()+i>k) && (st[1].top()>extra.front()))
        {
            total -= st[1].top();
            st[1].pop();
            total += extra.front();
            st[2].push(extra.front());
            extra.pop();
        }

        if(((st[0].size()+i)>=k) && ((st[1].size()+i) >= k) && ((st[0].size()+st[1].size()+st[2].size()+i) == m))
        {
            ans = min(ans,total);
        }
    }
    if(ans == mod*mod) ans = -1;
    printf("%lld\n", ans);
    return 0;
}

