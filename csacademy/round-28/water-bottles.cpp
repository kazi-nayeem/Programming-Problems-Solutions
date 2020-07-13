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

struct data
{
    int a, b, c;
    data(int a, int b, int c): a(a), b(b), c(c) {}
    bool operator < (const data & p) const
    {
        if(b != p.b) return b>p.b;
        return c>p.c;
    }
    void print()
    {
        printf("%d %d %d\n", a, b, c);
    }
};


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll sum;
    scanf("%d %lld", &n, &sum);
    priority_queue<data> qu;
    int l, r;
    int mi = mod+mod;
    int mx = 0;
    ll avg = sum/n;
    ll tem = sum;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &l, &r);
        qu.push(data(l,l,r));
        tem -= l;
    }
    while(!qu.empty())
    {
        //printf("-------------ok2-------\n");
        avg = sum/qu.size();
        int cnt = 0;
        while(!qu.empty() && qu.top().b < avg)
        {
            //printf("ok1\n");
            cnt++;
            data now = qu.top();
            qu.pop();
            if(now.c>avg)
            {
                tem -= avg-now.b;
                now.b = avg;
                qu.push(now);
                // puts("----");
                //now.print();
            }
            else
            {
                tem -= now.c-now.b;
                now.b = now.c;
                sum -= now.b;
                mi = min(mi,now.b);
                mx = max(mx,now.b);
                //now.print();
            }
        }
        if(cnt == 0)
        {
            data now = qu.top();
            qu.pop();
            sum -= now.b;
            mi = min(mi,now.b);
            mx = max(mx,now.b);
            //now.print();
        }
    }
//    while(!qu.empty())
//    {
//        data now = qu.top();
//        qu.pop();
//        if(sum)
//        {
//            now.b++;
//            sum -= now.b;
//        }
//        now.print();
//        mi = min(mi,now.b);
//        mx = max(mx,now.b);
//    }
    printf("%d\n", mx-mi);
    return 0;
}

