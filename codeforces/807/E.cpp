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

int two[MX];
int others[MX];
int n;
int pre[MX];

bool func(int k)
{
    if(two[0]<k) return false;
    int baki = two[0]-k+others[0];
    pre[0] = k;
    for(int i = 1; i < 64; i++)
    {

        pre[i] = min(pre[i-1],two[i]);
        int p = pre[i-1]-pre[i];
        baki -= p;
        baki += two[i]-pre[i]+others[i];
        if(baki<0) return false;
        //printf("%d %d %d\n", i, pre[i], baki);
    }
    if(baki == 0) return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        for(int j = 0; j < 64; j++)
        {
            ll p2 = 1ll<<j;
            if(p2 == x)
            {
                two[j]++;
                break;
            }
            if((p2<<1)>x)
            {
                others[j]++;
                break;
            }
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++)
    {
        if(func(i)) res.push_back(i);
    }
    if(res.size() == 0) res.push_back(-1);
    for(int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
    return 0;
}

