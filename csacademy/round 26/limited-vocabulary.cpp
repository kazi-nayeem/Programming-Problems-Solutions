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

int cnt[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string tem, ans = "";
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        cin>>tem;
        memset(cnt,0,sizeof cnt);
        int t = 0;
        for(int j = 0; j < (int) tem.size(); j++)
        {
            if(cnt[(int)tem[j]] == 0)
            {
                cnt[ (int)tem[j]] = 1;
                t++;
            }
        }
        //printf("%d\n", t);
        if(t<=k)
        {
            if(ans.size()<tem.size())
                ans = tem;
        }
    }
    if(ans == "")
    cout<<"-1"<<endl;
    else
    cout<<ans.size()<<endl;
    return 0;
}

