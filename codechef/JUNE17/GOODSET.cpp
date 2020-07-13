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

#define MX 1005
#define inf 100000000

const ll mod = 1000000007ll;

int arr[MX];
int flag[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    arr[1] = 1;
    arr[2] = 2;
    flag[1] = 1;
    flag[2] = 1;
    for(int i = 3; i <= 100; i++)
    {
        for(int j = 1; j+1 < i; j++)
            flag[arr[j]+arr[i-1]] = 1;
        for(int j = 1; j <= 500; j++)
        {
            if(flag[j] == 0)
            {
                flag[j] = 1;
                arr[i] = j;
                //printf("%d %d\n", i, j);
                break;
            }
        }
    }
//    for(int i = 1; i <= 100; i++)
//        printf("-->>%d\n", arr[i]);
    int ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        printf("%d", arr[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", arr[i]);
        puts("");
    }
    return 0;
}


