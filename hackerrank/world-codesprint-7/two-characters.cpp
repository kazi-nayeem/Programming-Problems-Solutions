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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int cnt[MX];
char str[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int len;
    scanf("%d %s", &len, str);
    for(int i = 0; i < len; i++)
    {
        cnt[str[i]]++;
    }
    int res = 0;
    for(int i = 'a'; i <= 'z'; i++)
        for(int j = 'a'; j <= 'z'; j++)
        {
            if(cnt[i] == 0 || cnt[j] == 0 || (cnt[i]-cnt[j]>1) || (cnt[i]<cnt[j])) continue;
            bool flag = true;
            int pre = j;
            for(int k = 0; k < len; k++)
            {
                if(str[k] != i && str[k] != j) continue;
                if(str[k] == pre)
                {
                    flag = false;
                    break;
                }
                else
                {
                    pre = str[k];
                }
            }
            if(flag) res = max(res,cnt[i]+cnt[j]);
        }
    printf("%d\n", res);
    return 0;
}

