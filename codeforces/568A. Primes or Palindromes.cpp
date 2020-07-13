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

#define MX 2000005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int flag[MX];
int pali[MX];

char str[100];

bool check(int a)
{
    sprintf(str,"%d", a);
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        if(str[i] != str[len-i-1])
            return false;
    return true;
}

void sieve()
{
    for(ll i = 2; i < MX; i++)
    {
        if(flag[i] == 1) continue;
        for(ll j = i+i; j < MX; j+=i)
            flag[j] = 1;
    }
    pali[0] = 0;
    pali[1] = 1;
    for(int i = 2; i < MX; i++)
    {
        flag[i] ^= 1;
        flag[i] += flag[i-1];
        if(check(i)) pali[i] = 1;
        pali[i] += pali[i-1];
    }
    /*for(int i = 1; i < 100; i++)
    {
        printf("%d %d %d\n", i, flag[i], pali[i]);
    }*/
}

int main()
{
    sieve();
    int p, q;
    scanf("%d %d", &p, &q);
    int ans = -1;
    for(int i = 1; i < MX; i++)
    {
        if(flag[i]*q <= pali[i]*p)
            ans = i;
    }
    if(ans != -1 && ans+5 < MX)
        printf("%d\n", ans);
    else
        printf("Palindromic tree is better than splay tree\n");
    return 0;
}


