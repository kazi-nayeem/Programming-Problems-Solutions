#include <bits/stdc++.h>

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

int main()
{
    int n;
    scanf("%d", &n);
    if(n<3)
    {
        printf("1\n1\n");
        return 0;
    }
    if(n==3)
    {
        printf("2\n1 3\n");
        return 0;
    }
    if(n==4)
    {
        printf("4\n3 1 4 2\n");
        return 0;
    }
    if(n>4)
    {
        printf("%d\n", n);
        for(int i = 1; i <= n; i+=2)
            printf("%d ", i);
        for(int i = 2; i <= n; i+=2)
            printf("%d ", i);
        return 0;
    }
    return 0;
}

