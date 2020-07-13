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

char str[3*MX];

int main()
{
    int len, q, res = 0;
    scanf("%d %d %s", &len, &q, str);

    for(int i = 1; i < len; i++)
    {
        if(str[i] == '.' && str[i-1] == '.') res++;
    }
    int pos;
    char ch;
    for(int i = 0; i < q; i++)
    {
        scanf("%d %c", &pos, &ch);
        pos--;
        if(str[pos] == ch || (ch != '.' && str[pos] != '.'));
        else if(ch == '.')
        {
            str[pos] = ch;
            if(pos > 0 && str[pos-1] == '.') res++;
            if(pos+1 < len && str[pos+1] == '.') res++;
        }
        else
        {
            str[pos] = ch;
            if(pos > 0 && str[pos-1] == '.') res--;
            if(pos+1 < len && str[pos+1] == '.') res--;
        }
        printf("%d\n", res);
    }
    return 0;
}

