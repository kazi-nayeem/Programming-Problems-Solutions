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
#include<bitset>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

char str[MX];
int flag[MX];

int main()
{
    gets(str);
    int len = strlen(str);
    for(int i = 1; i < len; i+=3)
        flag[str[i]-'a'] = 1;
    int s = 0;
    for(int i = 0; i < 26; i++)
        s += flag[i];
    printf("%d\n", s);
    return 0;
}


