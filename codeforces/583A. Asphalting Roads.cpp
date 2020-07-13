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

#define MX 105
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

int flag[MX][MX];

int main()
{
    int x, y;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n*n; i++)
    {
        scanf("%d %d", &x, &y);
        if(flag[x-1][y] == 1 || flag[x][y] == 1 || flag[x+1][y] == 1 || flag[x][y-1] == 1 || flag[x][y+1] == 1)
        {

        }
        else
        {
            printf("%d ", i);
            flag[x][y] = 1;
        }
    }
    puts("");
    return 0;
}


