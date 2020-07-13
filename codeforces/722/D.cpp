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
    int child;
    int nxt[2];
    data()
    {
        child = 0;
        nxt[0] = -1;
        nxt[1] = -1;
    }
};

void printll(ll a)
{
    for(int i = 34; i >= 0; i--)
    {
        printf("%lld", (a>>i)&1);
    }
    puts("");
    printf("a = %lld \n", a);
}

vector<data> vc;

void add(ll a)
{
    int pos = 0;
    for(int i = 0; i < 34; i++)
    {
        if((a>>i)&1ll)
            pos = i;
    }
    //puts("\nadd");
    //printll(a);
    int root = 0;
    vc[root].child++;
    for(int i = pos; i >= 0; i--)
    {
        //printf("%lld", (a>>i)&1);
        int p = 0;
        if((a>>i)&1)
        {
            p = 1;
        }
        if(vc[root].nxt[p] == -1)
        {
            vc.push_back(data());
            vc[root].nxt[p] = vc.size()-1;
        }
        root = vc[root].nxt[p];
        vc[root].child++;
        //printf("root %d %d\n", p, root);
    }
    //puts("");
}

void visit(int root, ll a, int p)
{

    if(p >= vc[root].child) return;
    printf("%d %lld %d\n", root, a, p);
    if(root != 0)
    {
        printll(a);
        p++;
    }
    //printf("%d %lld %d\n", root, a, p);
    if(vc[root].nxt[1] != -1)
    {
        int nx = vc[root].nxt[1];
        if(vc[nx].child > p)
        {
            visit(nx, (a<<1) + 1, p);
            p = 0;
        }
        else
        {
            p -= vc[nx].child;
        }
    }
    if(vc[root].nxt[0] != -1)
    {
        int nx = vc[root].nxt[0];
        if(vc[nx].child > p)
        {

            visit(nx, (a<<1), p);
            p = 0;
        }
        else
        {
            p -= vc[nx].child;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll x;
    vc.push_back(data());
    scanf("%d", &n);
    for(int i = 1; i<= n; i++)
    {
        scanf("%lld", &x);
        add(x);
    }
    visit(0,0,0);
    return 0;
}

