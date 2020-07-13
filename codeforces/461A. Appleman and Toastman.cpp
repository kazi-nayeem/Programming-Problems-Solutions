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
using namespace std;

#define MX 300005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;


int arr[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr,arr+n);
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        res += (ll) (i+2ll)*arr[i];
    }
    res -= arr[n-1];
    cout<<res<<endl;
    return 0;
}


