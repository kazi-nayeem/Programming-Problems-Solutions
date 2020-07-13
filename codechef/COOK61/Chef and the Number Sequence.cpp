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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000007ll;

int arr[100], n, k;
int res[100];

int main()
{
    int l;
    int te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d %d %d", &n, &k, &l);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        memset(dp,-1,sizeof dp);
        ll res = 0;
        //for(int i = 0; i <= l; i++)
            res = (res+rec(0,l))%mod;
        printf("%lld\n", res);
    }
    return 0;
}


