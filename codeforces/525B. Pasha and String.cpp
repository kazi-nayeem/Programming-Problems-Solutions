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

#define MX 1000005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int deg[MX];
char str[MX];

int main()
{
    gets(str);
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        deg[m-1]++;
    }
    int t = 0;
    int len = strlen(str);
    for(int i = 0; i < len/2; i++)
    {
        t += deg[i];
        if(t%2 == 1)
        {
            //swap(str[i],str[len-i-1]);
            char c = str[i];
            str[i] = str[len - i - 1];
            str[len-i-1] = c;
        }
    }
    cout<<str;
    return 0;
}
