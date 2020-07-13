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
    int n,m,k;
    int a = 1,b = 1;
    scanf("%d%d%d", &n, &m, &k);
    bool flag = true;

    for(int i = 1; i < k;)
    {
        if(flag)
        {
            printf("2");
            flag = false;
        }
        else
        {
            i++;
            flag =true;
        }
        printf(" %d %d", a, b);
        if(flag) puts("");
        if(a%2 == 1)
        {
            if(b == m) a++;
            else b++;
        }
        else
        {
            if(b == 1) a++;
            else b--;
        }
    }
    int p = n*m-2*k+2;
    printf("%d", p);
    for(int i = 0;i < p; i++)
    {
        printf(" %d %d", a, b);
        if(a%2 == 1)
        {
            if(b == m) a++;
            else b++;
        }
        else
        {
            if(b == 1) a++;
            else b--;
        }
    }
    return 0;
}
