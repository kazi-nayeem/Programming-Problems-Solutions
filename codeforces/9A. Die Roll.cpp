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

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a = max(a,b);
    a = 6-a+1;
    printf("%d/%d", a/__gcd(a,6), 6/__gcd(a,6));
    return 0;
}


