#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define ll long long
#define MX 1000000000000LL

vector<ll> vc;
map<ll,char> mp;

int main()
{
    vc.push_back(4);
    vc.push_back(7);
    mp[4] = mp[7] = 1;
    for(int i = 0; i < vc.size(); i++)
    {
        ll tem = vc[i]*10+4;
        if(tem <= MX && mp.find(tem) == mp.end())
        {
            vc.push_back(tem);
            mp[tem] = 1;
        }
        tem = vc[i]*10+7;
        if(tem <= MX && mp.find(tem) == mp.end())
        {
            vc.push_back(tem);
            mp[tem] = 1;
        }
    }
    int sz = vc.size();
    printf("%d\n", sz);
    for(int i = 0; i < vc.size(); i++)
        for(int j = 0; j < sz; j++)
        {
            ll tem = vc[i]*vc[j];
            if(tem <= MX && mp.find(tem) == mp.end())
            {
                vc.push_back(tem);
                mp[tem] = 1;
            }
        }
    sort(vc.begin(),vc.end());
    /*for(int i = 0; i < 20; i++)
        printf("%lld\n", vc[i]);
    printf("%d\n", vc.size());*/
    int te, ti;
    ll a, b;
    //scanf("%d", &ti);
    ti = 0;
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &a, &b);
        printf("Case %d: %d\n", te, upper_bound(vc.begin(),vc.end(),b)-lower_bound(vc.begin(),vc.end(),a));
    }
    return 0;
}
