//#include <bits/stdc++.h>

#include<cstdio>
#include<algorithm>
using namespace std;

#define MX 1001
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000007ll;

int arr1[MX];
int arr2[MX];
int n;

ll func()
{
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);

    ll res = 1;
    int pos = -1;
    for(int i = 0; i < n; i++)
    {
        while(pos+1 < n && arr1[pos+1] <= arr2[i]) pos++;
        //printf("%d\n", pos);
        if(pos >= i)
            res *= (pos-i+1);
        else
            return 0;
        res %= mod;
    }

    return res;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr2[i]);

        printf("Case %d: %lld\n", te, func());
    }
    return 0;
}


