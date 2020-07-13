//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include  <time.h>
using namespace std;

#define s 100010
#define ll long long

bool col[s];
int mob[s]; //mobius function
vector<int> divi[s];

int seive()//1 indexed
{
    long long i,j;
    col[0]=true;
    col[1]=true;
    for(i = 1; i<s; i++) mob[i]=1;
    for(i=2; i<s; i++)
        if(!col[i])
        {
            mob[i]=-1;
            for(j=2*i; j<s; j+=i)
            {
                col[j]=true;
                if(j%(i*i)==0) mob[j]=0; //divisible by square of prime
                mob[j]*=-1;
            }
        }
    for(i = 1; i < s; i++)
        for(j = i; j < s; j+=i)
            divi[j].push_back(i);
    return 0;
}

const ll mod =1000000007ll;
ll fact[s];
ll ifact[s];

ll bigmod(ll a, ll p)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2);
    res = (res*res)%mod;
    if(p%2)
        res = (res*a)%mod;
    return res;
}

int main()
{
    //srand(time(NULL));
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1; i < s; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = bigmod(fact[i],mod-2);
    }
    seive();
    int t, n, f;
    cin>>t;
    while(t--)
    {
        scanf("%d%d", &n, &f);
        ll total = 0ll;
        for(int i = 0; i < divi[n].size(); i++)
        {
            int k = divi[n][i];
            if(k<f)continue;
            if(k == f){
                total += (total+mob[n/k]+mod)%mod;
                continue;
            }
            int d = k-f;
            ll e = (fact[d + f - 1] * ifact[f - 1]) % mod;
            e = (e * ifact[d]) % mod;
            e *= mob[n/k];
            e = (e+mod)%mod;
            total += e;
            total %= mod;
        }
        printf("%I64d\n", total);
    }
    return 0;
}
