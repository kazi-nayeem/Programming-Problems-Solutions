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

#define MX 500005
#define MXP 303
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int flag[MX];
int arr[MX];
int prime[MXP];
int totalp;
ll res;

vector<int> primfact;

void sieve()
{
    prime[0] = 2;
    totalp = 1;
    for(int i = 3; i < 2000; i+=2)
    {
        if(flag[i]) continue;
        prime[totalp++] = i;
        for(int j = i*i; j < 2000; j += i*2)
            flag[j] = 1;
    }
    //printf("%d\n", totalp);
}

void factorize(int n)
{
    primfact.clear();
    for(int i = 0; i < totalp && prime[i]*prime[i] <= n; i++)
    {
        int cnt = 0;
        while(n%prime[i] == 0)
        {
            cnt++;
            n /= prime[i];
        }
        if(cnt == 0) continue;
        primfact.push_back(prime[i]);
    }
    if(n>1)primfact.push_back(n);
}

void add(int pos, int val, int tk)
{
    if(pos == primfact.size())
    {
        if(tk%2)
            res -= arr[val];
        else
            res += arr[val];
        arr[val]++;
        return;
    }
    add(pos+1,val,tk);
    add(pos+1,val*primfact[pos],tk+1);
}

void remov(int pos, int val, int tk)
{
    if(pos == primfact.size())
    {
        arr[val]--;
        if(tk%2)
            res += arr[val];
        else
            res -= arr[val];
        return;
    }
    remov(pos+1,val,tk);
    remov(pos+1,val*primfact[pos],tk+1);
}

int fina[MX];

int main()
{
    sieve();
    memset(flag,0,sizeof flag);
    int n, q, x;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &fina[i]);
        //factorize(x);
        //flag[x] = 1;
        //for(int i = 0; i < primfact.size(); i++)
        //printf("%d ", primfact[i]);
        //puts("");
        //add(0,1,0);
        //printf("%lld\n", res);
    }
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        factorize(fina[x]);
        //printf("pre  %lld  ", res);
        if(flag[x] == 0)
        {
            flag[x] = 1;
            add(0,1,0);
            n++;
        }
        else
        {
            n--;
            flag[x] = 0;
            remov(0,1,0);
        }
        printf("%lld\n", res);
    }
    return 0;
}


