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

struct data
{
    ll num;
    int ty;
};

data arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i].num);
            arr[i].ty = i%2;
        }
        if(n%2 == 0)
        {
            if(n == 2)
            {
                if(arr[1].num == 1)
                {
                    arr[2].num++;
                }
                else
                {
                    arr[3].ty = 1;
                    arr[3].num = arr[1].num-1;
                    arr[2].num++;
                    arr[1].num = 1;
                    n++;
                }
            }
            else
            {
                arr[n+1].num = arr[n-1].num-1;
                arr[n+1].ty = 1;
                arr[n].num++;
                arr[n-1].num = 1;
                arr[n-2].num--;
                n++;
            }
        }
        else
        {
            if(n == 1)
            {
                arr[3].num = arr[1].num-1;
                arr[3].ty = 1;
                arr[2].ty = 0;
                arr[2].num = 1;
                arr[1].num = 1;
                n = 3;
            }
            else
            {
                arr[n+2].num = arr[n].num-1;
                arr[n+2].ty = 1;
                arr[n+1].ty = 0;
                arr[n+1].num = 1;
                arr[n].num = 1;
                arr[n-1].num--;
                n += 2;
            }
        }
        //for(int i = 0; i <= n; i++)
        // printf("%lld %d\n", arr[i].num, arr[i].ty);
        for(int i = 1; i <= n; i++)
        {
            //printf("%d\n", i);
            while(arr[i].num == 0 && i <= n)
            {
                //printf("->>> %d\n", i);
                for(int j = i; j < n; j++)
                    arr[j] = arr[j+1];
                n--;
            }
            while( i>1 && i <= n && arr[i].ty == arr[i-1].ty)
            {
                //printf("-<<<< %d\n", i);
                arr[i-1].num += arr[i].num;
                for(int j = i; j < n; j++)
                {
                    arr[j] = arr[j+1];
                }
                n--;
            }
            //printf("Ok\n");
        }
        printf("%d\n", n);
        for(int i = 1; i <= n; i++)
            printf("%lld ", arr[i].num);
        puts("");
    }
    return 0;
}

