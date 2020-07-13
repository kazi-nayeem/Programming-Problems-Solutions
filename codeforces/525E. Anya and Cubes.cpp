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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

map<pair<ll,int>,ll> mp, mp2, newm;
vector<pair<ll,int> > vc, newv;
ll fact[20];
int arr[30];

int main()
{
    fact[0] = 1;
    for(int i = 1; i < 20; i++)
        fact[i] = fact[i-1]*i;
    int n, k;
    ll s;
    scanf("%d %d %I64d", &n, &k, &s);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    vc.clear();
    mp.clear();
    mp[make_pair(0ll,0)] = 1ll;
    vc.push_back(make_pair(0ll,0));
    for(int i = n/2; i >= 0; i--)
    {
        int sz = vc.size();
        newm.clear();
        newv.clear();
        for(int j = 0; j < sz; j++)
        {
            ll made = vc[j].first;
            int coin = vc[j].second;

            pair<ll,int> tem = make_pair(made+arr[i],coin);
            if(tem.first <= s)
            {
                if(newm.find(tem) == newm.end())
                {
                    newv.push_back(tem);
                    newm[tem] = 0;
                }
                newm[tem] += mp[vc[j]];
            }
            if(arr[i] >= 19) continue;
            tem = make_pair(made+fact[arr[i]],coin+1);
            if(tem.first <= s && tem.second <= k)
            {
                if(newm.find(tem) == newm.end())
                {
                    newv.push_back(tem);
                    newm[tem] = 0;
                }
                newm[tem] += mp[vc[j]];
            }
        }
        for(int j = 0; j < newv.size(); j++)
        {
            if(mp.find(newv[j]) == mp.end())
            {
                vc.push_back(newv[j]);
                mp[newv[j]] = 0;
            }
            mp[newv[j]] += newm[newv[j]];
        }
    }

    vc.clear();
    mp2.clear();
    mp2[make_pair(0ll,0)] = 1ll;
    vc.push_back(make_pair(0ll,0));
    for(int i = n/2+1; i < n; i++)
    {
        int sz = vc.size();
        newm.clear();
        newv.clear();
        for(int j = 0; j < sz; j++)
        {
            ll made = vc[j].first;
            int coin = vc[j].second;

            pair<ll,int> tem = make_pair(made+arr[i],coin);
            if(tem.first <= s)
            {
                if(newm.find(tem) == newm.end())
                {
                    newv.push_back(tem);
                    newm[tem] = 0;
                }
                newm[tem] += mp2[vc[j]];
            }
            if(arr[i] >= 19) continue;
            tem = make_pair(made+fact[arr[i]],coin+1);
            if(tem.first <= s && tem.second <= k)
            {
                if(newm.find(tem) == newm.end())
                {
                    newv.push_back(tem);
                    newm[tem] = 0;
                }
                newm[tem] += mp2[vc[j]];
            }
        }
        for(int j = 0; j < newv.size(); j++)
        {
            if(mp2.find(newv[j]) == mp2.end())
            {
                vc.push_back(newv[j]);
                mp2[newv[j]] = 0;
            }
            mp2[newv[j]] += newm[newv[j]];
        }
    }
    ll res = 0;
    for(int i = 0; i < vc.size(); i++)
    {
        for(int j = vc[i].second; j <= k; j++)
        {
            if(mp.find(make_pair(s-vc[i].first,j-vc[i].second)) != mp.end())
            {
                res += mp2[vc[i]] * mp[make_pair(s-vc[i].first,j-vc[i].second)];
            }
        }
    }
    printf("%I64d\n", res);
    return 0;
}


