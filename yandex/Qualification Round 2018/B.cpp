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
#include<complex>
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

#define MX 500
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

int arr[MX][MX];
int flag[(MX*MX)];
int ind[(MX*MX)];
int res[MX][MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int pos;
    for(int i = 1; i <= 2*n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        flag[arr[i][1]]++;
        if(flag[arr[i][1]] == 2)
        {
            pos = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        res[i][1] = arr[pos][i];
        ind[res[i][1]] = i;
    }
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++)
//            printf("%d ", res[i][j]);
//        puts("");
//    }
    for(int i = 1; i <= 2*n; i++)
    {
        if(i == pos)
            continue;
        if(ind[arr[i][1]] == 0)
            continue;
        int now = ind[arr[i][1]];
        for(int j = 1; j <= n; j++)
        {
            res[now][j] = arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != 1 || j != 1) printf(" ");
            printf("%d", res[i][j]);
        }
    }
    puts("");
    return 0;
}
