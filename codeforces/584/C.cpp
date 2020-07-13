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

#define MX 105005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

char str1[MX];
char str2[MX];
char str[MX];
bool flag[MX];
int n, k;

char func(char a, char b)
{
    for(int i = 0; i < 26; i++)
    {
        if(a != i+'a' && b != i+'a') return i+'a';
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf(" %s %s", str1, str2);
    int di = 0;
    for(int i = 0; i < n; i++)
    {
        if(str1[i] != str2[i]) di++;
        str[i] = str1[i];
    }
    if(k < ((di+1)/2))
    {
        puts("-1");
        return 0;
    }
    if(k < di)
    {
        int a = k;
        for(int i = 0; i < n; i++)
        {
            if(str1[i] != str2[i])
            {
                if(a > 0) str[i] = str1[i], a--;
                else
                    str[i] = str2[i];
            }
        }
        int di1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] != str1[i]) di1++;
        }
        if(di1 < k)
        {
            for(int i = 0; i < n; i++)
            {
                if(str1[i] != str2[i] && str1[i] == str[i] && di1 < k)
                {
                    di1++;
                    str[i] = func(str1[i],str2[i]);
                }
            }
        }
        //puts(str);
        puts(str);
        return 0;
    }
    int mx = k-di;
    k -= mx;
    for(int i = 0; i < n && mx > 0; i++)
    {
        if(str1[i] == str2[i] && !flag[i])
        {
            flag[i] = true;
            mx--;
            str[i] = func(str1[i], str2[i]);
        }
    }
    for(int i = 0; i < n && k > 0; i++)
    {
        if(str1[i] != str2[i] && !flag[i])
        {
            flag[i] = true;
            k--;
            str[i] = func(str1[i], str2[i]);
        }
    }
    for(int i = 0; i < n && k > 0; i++)
    {
        if(str1[i] == str2[i] && !flag[i])
        {
            flag[i] = true;
            k--;
            str[i] = func(str1[i], str2[i]);
        }
    }
    puts(str);
    return 0;
}


