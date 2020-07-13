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

char str1[100], str2[100];

int main()
{
    int te;
    scanf("%d", &te);
    while(te--)
    {
        scanf(" %s %s", str1, str2);
        int len = strlen(str1);
        if(len != strlen(str2))
        {
            puts("No");
            continue;
        }
        bool flag = true;
        for(int i = 0; i < len; i++)
        {
            if(str1[i] == '?'|| str2[i] == '?') continue;
            if(str1[i] != str2[i]) flag = false;
        }
        if(flag)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}


