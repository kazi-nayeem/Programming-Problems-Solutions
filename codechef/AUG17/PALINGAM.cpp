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

int cnt1[100];
int cnt2[100];
char str[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf(" %s", str);
        int len = strlen(str);
        memset(cnt1,0,sizeof cnt1);
        for(int i = 0; i < len; i++)
            cnt1[str[i]-'a']++;
        scanf(" %s", str);
        len = strlen(str);
        memset(cnt2,0,sizeof cnt2);
        for(int i = 0; i < len; i++)
            cnt2[str[i]-'a']++;
        char flag = 'B';
        for(int i = 0; i < 26; i++)
        {
            if(cnt2[i] == 0 && cnt1[i]>=2)
            {
                flag = 'A';
                break;
            }
        }
        bool one =
        for(int i = 0; i < 26 && flag == 'B'; i++)
        {

        }
        printf("%c\n", flag);
    }
    return 0;
}
