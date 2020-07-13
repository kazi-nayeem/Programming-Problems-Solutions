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

string str;
int len;
map<string,int> mp;
int flag[200];

bool allBlock()
{
    for(int i = 0; i < len; i++)
        if(flag[i] == 0)
            return false;
    return true;
}

int check(string now)
{
    memset(flag,0,sizeof flag);
    while(!allBlock())
    {
        bool match = false;
        for(int i = 0; i+now.size() <= len; i++)
        {
            int notBlock = 0;
            bool fullmatch = true;
            for(int j = 0; j < now.size(); j++)
            {
                if(flag[i+j])
                    continue;
                if(str[i+j] != now[j])
                {
                    fullmatch = false;
                    break;
                }
                notBlock++;
            }
            if(fullmatch && notBlock>0)
            {
                for(int j = 0; j < now.size(); j++)
                    flag[i+j] = 1;
                match = true;
            }
        }
        if(!match)
            return 0;
    }
    if(allBlock())
        return 1;
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>str;
    len = str.size();
    for(int i = 0; i < len; i++)
        for(int j = 1; i+j<=len; j++)
        {

            string tem = str.substr(i,j);
            //cout<<tem<<endl;
            if(mp.find(tem) != mp.end())
                continue;
            mp[tem] = check(tem);
        }
    //puts("ok");
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if((it->second))
            cout<<(it->first)<<endl;
    }
    return 0;
}

