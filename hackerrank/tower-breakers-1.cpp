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

#define MX 1005005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

vector<int> adj[MX];

int arr[MX];
int flag[MX];

void func()
{
    /*for(int i = 1; i < MX; i++)
    {
        for(int j = i<<1; j < MX; j+=i)
            adj[j].push_back(i);
    }
    for(int i = 2; i < MX; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
        {
            flag[arr[adj[i][j]]] = i;
        }
        for(int j = 0; j < MX; j++)
            if(flag[j] != i)
            {
                arr[i] = j;
                break;
            }
    }
    for(int i = 0; i < 100; i++)
    {
        printf("%d g-> %d ->", i, arr[i]);
        for(int j = 0; j < adj[i].size(); j++)
            printf("%d ", adj[i][j]);
        puts("");
    }*/
    arr[0] = 2;
    int pos = 1;
    for(ll i = 3; i < MX; i+=2)
    {
        if(flag[i]) continue;
        arr[pos++] = i;
        for(ll j = i*i; j < MX; j+= i*2)
            flag[j] = 1;
    }
    //for(int i = 0; i < 100; i++)
      //  printf("%d\n", arr[i]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    func();
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d", &n, &m);
        if(m == 1)
            printf("1");
        else if(n%2 == 0)
            printf("2");
        else
            printf("1");
        puts("");
    }
    return 0;
}


