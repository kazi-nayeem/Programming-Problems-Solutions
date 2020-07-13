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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int arr[MX][MX];
int sor[MX*MX];
int res[MX];

map<int,int> mp;

int main()
{
    int a = 0, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            sor[a++] = arr[i][j];
            mp[arr[i][j]]++;
        }
    sort(sor,sor+a);
    a--;
    for(int i = 0; i < n; i++)
    {
        while(mp[sor[a]] == 0) a--;
        res[i] = sor[a--];
        mp[__gcd(res[i],res[i])]--;
        for(int j = 0; j < i; j++)
        {
            mp[__gcd(res[i],res[j])]-=2;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", res[i]);
    puts("");
    return 0;
}


