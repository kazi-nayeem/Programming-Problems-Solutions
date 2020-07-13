#include <bits/stdc++.h>

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

vector<ll> vc;

int main()
{
    ll n;
    cin>>n;
    if(n >= 4) vc.push_back(4);
    if(n >= 7) vc.push_back(7);
    for(int i = 0; i < vc.size(); i++)
    {
        ll tem = vc[i]*10ll+4ll;
        if(tem <= n) vc.push_back(tem);
        tem = vc[i]*10ll+7ll;
        if(tem <= n) vc.push_back(tem);
    }
    printf("%d\n", vc.size());
    return 0;
}

