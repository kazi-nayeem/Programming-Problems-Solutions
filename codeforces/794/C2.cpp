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

char str1[MX];
char str2[MX];
char ans[MX];

int cnt1[1000];
int cnt2[1000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s %s", str1, str2);
    int len = strlen(str1);
    for(int i = 0; i < len; i++)
    {
        cnt1[str1[i]-'a']++;
        cnt2[str2[i]-'a']++;
    }

    int st = 0, en = len-1;
    int pos = -1;
    int a = 0, b = 26;
    for(int i = 0; i < len; i++)
    {
        while(cnt1[a] == 0 && a < 30) a++;
        while(b >= 0 && cnt2[b] == 0) b--;
        if(a>b) break;
        pos = i;
        if(i%2 == 0)
        {
            if(a<=b)
            {
                ans[st++] = a+'a';
            }
            else
            {
                ans[en--] = a+'a';
            }
            cnt1[a]--;
        }
        else
        {
            if(a<=b)
            {
                ans[st++] = b+'a';
            }
            else
            {
                ans[en--] = b+'a';
            }
            cnt2[b]--;
        }
    }
    a = 26, b = 0;
    for(int i = 0; i < len; i++)
    {
        while(cnt1[a] == 0 && a < 30) a++;
        while(b >= 0 && cnt2[b] == 0) b--;
        if(a>b) break;
        pos = i;
        if(i%2 == 0)
        {
            if(a<=b)
            {
                ans[st++] = a+'a';
            }
            else
            {
                ans[en--] = a+'a';
            }
            cnt1[a]--;
        }
        else
        {
            if(a<=b)
            {
                ans[st++] = b+'a';
            }
            else
            {
                ans[en--] = b+'a';
            }
            cnt2[b]--;
        }
    }
    puts(ans);
    return 0;
}

