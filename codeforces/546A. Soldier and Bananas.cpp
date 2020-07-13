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
using namespace std;

#define ll long long

int main()
{
    ll n, k, w;
    cin>>k>>n>>w;
    ll res = (w+1ll)*w;
    res/=2;
    res *= k;
    res = max(0ll,res-n);
    cout<<res<<endl;
    return 0;
}

