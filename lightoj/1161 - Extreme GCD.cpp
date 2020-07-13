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

#define MX 10005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

vector<int> fact[MX];
ll sum[MX][3];

ll res;

void add(int pos, const int n, int val, int tk)
{
    if(fact[n].size() == pos)
    {
        if(tk%2)
            res -= sum[val][2];
        else
            res += sum[val][2];
        sum[val][2] += sum[val][1];
        sum[val][1] += sum[val][0];
        sum[val][0]++;
        return;
    }
    add(pos+1,n,val,tk);
    add(pos+1,n,val*fact[n][pos],tk+1);
}

void sieve()
{
    for(int i = 2; i < MX; i+=2)
    {
        fact[i].push_back(2);
    }
    for(int i = 3; i < MX; i+=2)
    {
        if(fact[i].size() > 0) continue;
        for(int j = i; j < MX; j+=i)
            fact[j].push_back(i);
    }
    return;
}

int main()
{
    sieve();
    int n, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        res = 0;
        memset(sum,0,sizeof sum);
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            add(0,x,1,0);
        }
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}


