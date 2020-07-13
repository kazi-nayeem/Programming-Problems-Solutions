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

vector<pair<ll,string> > vc[2];

ll check(ll mx, ll k)
{
    int pos = vc[1].size()-1;
    ll res = 0;
    for(int i = 0; i < vc[0].size(); i++)
    {
        ll co1 = vc[0][i].first;
        while((pos>=0) && (co1+vc[1][pos].first>mx)) pos--;
        if(pos<0) break;
        //printf("%d %d\n", i, pos);
        res += pos+1;
    }
    return res;
}

ll mat[100][100];
int last;
char str[100];
int noch;

void back_track(const int in, int r, ll cost, int stpos)
{
    //printf("%d %d %lld %d\n", in, r, cost, stpos);
    if(r == last)
    {
        str[stpos] = 0;
        vc[in].push_back(make_pair(cost,(string) str));
        return;
    }
    for(int i = 0; i < noch; i++)
    {
        str[stpos] = 'a'+i;
        back_track(in,r+1,cost+mat[r][i],stpos+1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll k;
    scanf("%d %d %lld", &noch, &n, &k);
    k = pow(noch,n)-k+1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < noch; j++)
        {
            scanf("%lld", &mat[i][j]);
        }
    }
    last = n/2;
    back_track(0,0,0,0);

    //printf(">>>>>>>>>>>>>\n");
    int pre = last;
    last = n;
    //printf("pre   %d %d\n", pre, last);
    back_track(1,pre,0,0);
    sort(vc[0].begin(),vc[0].end());
    sort(vc[1].begin(),vc[1].end());
    /*for(int i = 0; i < vc[0].size(); i++)
    {
        printf("%d %lld %s\n", i, vc[0][i].first, vc[0][i].second.c_str());
    }
    for(int i = 0; i < vc[1].size(); i++)
    {
        printf("%d %lld %s\n", i, vc[1][i].first, vc[1][i].second.c_str());
    }*/
    ll low = 0, high = 1e14+10;
    ll res = -1;
    while(low<=high)
    {

        ll mid = (low+high)/2;
        //printf("%lld %lld %lld\n", low, high, low);
        if(check(mid,k)>=k)
        {
            // printf("ok\n");
            high = mid-1;
            res = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    //check(51,k);
    //printf("%lld\n", res);
    int pos = vc[1].size()-1, st = vc[1].size();
    string tem = "zzzzzzzzzzzzzzzzzzzzzz";
    k -= check(res-1,k);
    for(int i = 0; i < vc[0].size(); i++)
    {

        ll co1 = vc[0][i].first;
        while((pos>=0) && (co1+vc[1][pos].first>res)) pos--;
        if(pos<0) break;
        if(st>pos) st = pos+1;
        while((st>0) && (co1+vc[1][st-1].first==res)) st--;
        if(st>pos) continue;
        //printf("---%d %d %d\n", i, pos, st);
        if(k>(pos-st+1))
        {
            k -= pos-st+1;
        }
        else
        {
            tem = vc[0][i].second+vc[1][st+k-1].second;
            break;
        }
    }
    puts(tem.c_str());
    return 0;
}

