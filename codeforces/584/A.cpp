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

char str[MX];

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    if(n == 1 && t == 10)
    {
        puts("-1");
        return 0;
    }
    for(int i = 1; i < n; i++)
        str[i] = '0';

    str[0] = '1';
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum *= 10;
        sum += str[i]-'0';
        sum %= t;
    }
    if(sum != 0)
        str[n-1] += t-sum;
    puts(str);
    return 0;
}


