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

int cnt1[100];
int cnt2[100];
char str1[10000];
char str2[10000];

bool check()
{
    for(int i = 0; i < 10; i++)
    {
        if(cnt1[i] == 0 && cnt2[i] == 0) continue;
        if(cnt1[i]>0 && cnt2[i]>0) continue;
        return false;
    }
    return true;
}

bool change(int i, int j, int cnt[])
{
    if(i>0 && j < 9)
    {
        cnt[i]--;
        cnt[i-1]++;
        cnt[j]--;
        cnt[j+1]++;
        bool ans = check();
        cnt[i]++;
        cnt[i-1]--;
        cnt[j]++;
        cnt[j+1]--;
        return ans;
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--)
    {
        memset(cnt1,0,sizeof cnt1);
        memset(cnt2,0,sizeof cnt2);
        scanf("%s %s", str1, str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        for(int i = 0; i < len1; i++)
            cnt1[str1[i]-'0']++;
        for(int i = 0; i < len2; i++)
            cnt2[str2[i]-'0']++;
        if(check())
        {
            puts("friends");
            continue;
        }
        bool flag = false;
        for(int i = 1; i < len2; i++)
        {
            if(flag) break;
            flag = change(str2[i]-'0',str2[i-1]-'0', cnt2);
            if(flag) break;
            flag = (str2[i]>'1' || i > 1) && change(str2[i-1]-'0',str2[i]-'0', cnt2);

        }
        if(flag)
        {
            puts("almost friends");
            continue;
        }
        for(int i = 1; i < len1; i++)
        {
            if(flag) break;
            flag = change(str1[i]-'0',str1[i-1]-'0', cnt1);
            if(flag) break;
            flag = (str1[i-1]>'1' || i > 1) && change(str1[i-1]-'0',str1[i]-'0', cnt1);

        }
        if(flag)
        {
            puts("almost friends");
            continue;
        }

        puts("nothing");

    }
    return 0;
}

/**
5
123 32331313323213
123 22121221
123 2223042
137 470
7137 470
*/

