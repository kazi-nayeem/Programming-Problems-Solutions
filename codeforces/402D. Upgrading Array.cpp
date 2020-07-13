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

#define MX 36622
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int flag[MX];
int prime[MX];
int totalprime;

map<int,char> mp;

void sieve()
{
    prime[0] = 2;
    totalprime = 1;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 1 ) continue;
        prime[totalprime++] = i;
        for(int j = i*i; j < MX; j+=2*i)
            flag[j] = 1;
    }
}

int func(int n)
{
    int res = 0;
    for(int i = 0; i < totalprime && prime[i]*prime[i] <= n; i++)
    {
        int cnt = 0;
        while(n%prime[i] == 0)
        {
            cnt++;
            n /= prime[i];
        }
        if(cnt == 0) continue;
        if(mp.find(prime[i]) == mp.end())
            res += cnt;
        else
            res -= cnt;
    }
    if(n>1)
    {
        if(mp.find(n) == mp.end())
            res += 1;
        else
            res -= 1;
    }
    return res;
}

int arr[10000];

int main()
{
    sieve();
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        mp[x] = 1;
    }
    int res = -100000000;
    int total = 0;
    int gcd = 0;
    for(int i = 1; i <= n; i++)
    {
        int g = __gcd(gcd,arr[i]);
        int t = gcd/g;
        //printf("t = %d\n", t);
        total += func(t)*(i-1);
        total += func(arr[i]/g);
        printf("%10d %5d\n", arr[i], func(arr[i]));
        gcd = g;
        res = max(res,total);
        //printf("%d %d\n", res, total);
    }
    printf("%d\n", gcd);
    printf("%d\n", res);
    return 0;
}

/**

29 1
55296 10368 6912 165888 20736 331776 36864 41472 1152 221184 1728 2304 18432 82944 73728 147456 576 13824 442368 864 288 5184 663552 110592 4608 3456 2592 27648 9216
3


*/
