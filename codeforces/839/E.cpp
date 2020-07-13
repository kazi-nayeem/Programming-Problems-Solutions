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

#define MX 105
#define inf 100000000

const ll mod = 1000000007ll;

double value[MX];
int degree[MX];
int mat[MX][MX];
int flag[MX];
int n, k;
double ans;

void back_track(int pos)
{
    if(pos == n)
    {
        int total = 0;
        memset(degree,0,sizeof degree);
        for(int i = 0; i < n; i++)
        {
            if(flag[i] == 0) continue;
            for(int j = 0; j < n; j++)
            {
                degree[i] += mat[i][j]&flag[j];
                total += mat[i][j]&flag[j];
            }
        }
        if(total == 0) return;
        for(int i = 0; i < n; i++)
        {
            if(flag[i] == 0)continue;
            value[i] = (double) k*degree[i]/total;
        }
        double now = 0;
        for(int i = 0; i < n; i++)
        {
            if(flag[i] == 0) continue;
            for(int j = i+1; j < n; j++)
            {
                if(flag[j] == 1 && mat[i][j] == 1)
                    now += value[i]*value[j];
            }
        }
//        for(int i = 0; i < n; i++)
//            printf("%d ", flag[i]);
//        printf("\n%f\n", now);
        ans = max(ans,now);
        return;
    }
    flag[pos] = 1;
    back_track(pos+1);
    flag[pos] = 0;
    back_track(pos+1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    ans = 0;
    back_track(0);
    printf("%.10f\n", ans);
    return 0;
}


