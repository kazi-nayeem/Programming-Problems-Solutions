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

vector<ll> arr;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        arr.clear();
        scanf("%d", &n);
        ll total = 0;
        ll negtotal = 0;
        ll ans = 0;
        ll cnt = 0;
        ll x;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &x);
            if(x<0)
            {
                ans += x;
                negtotal += x;
                arr.push_back(x);
            }
            else
            {
                total += x;
                cnt++;
            }
        }
        ans += total*cnt;
        sort(arr.begin(), arr.end());
        //printf("%lld\n", ans);
        for(int i = arr.size()-1; i >= 0; i--)
        {
            negtotal -= arr[i];
            total += arr[i];
            cnt++;
            ans = max(ans,negtotal+total*cnt);
        }
        printf("%lld\n", ans);
    }
    return 0;
}


