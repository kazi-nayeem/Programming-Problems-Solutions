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

#define MX 100005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

deque<int> qu;
pair<int, int> res[MX];
int arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        qu.push_back(x);
    }

    for(int i = 1; i < n; i++)
    {
        int a = qu.front();
        qu.pop_front();

        int b = qu.front();
        qu.pop_front();

        res[i] = make_pair(a,b);
        qu.push_front(max(a,b));
        qu.push_back(min(a,b));

    }

    int con = qu.front();
    qu.pop_front();

    for(int i = 0; i < n-1; i++)
    {
        arr[i] = qu.front();
        qu.pop_front();
    }

    for(int i = 0; i < q; i++)
    {
        ll m;
        scanf("%lld", &m);
        if(m<n)
            printf("%d %d\n", res[m].first, res[m].second);
        else
            printf("%d %d\n", con, arr[(m-n)%(n-1)]);
    }

    return 0;
}

