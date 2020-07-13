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


int main()
{
    ll a, b, n;
    cin>>a>>b>>n;
    while(n--){
        ll l, m, t;
        cin>>l>>t>>m;
        ll total = (l-1)*(2*a+(l-2)*b)/2ll;
        total += m*t;
        ll tem = (2*a-b);
        tem *= tem;
        tem += 8*b*total;
        if(tem < 0){
            puts("-1");
            continue;
        }
        tem = sqrt(tem);
        tem -= 2*a-b;

        /*if(tem%(2*b)){
            puts("-1");
            continue;
        }*/
        tem /= 2*b;
        tem = min(tem,(t-a+b)/b);
        if(tem < l){
            puts("-1");
        }
        else
            cout<<tem<<endl;
    }
    return 0;
}


