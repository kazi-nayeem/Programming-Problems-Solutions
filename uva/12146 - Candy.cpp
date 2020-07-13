/*
Shamim Ehsan
SUST CSE 12
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};

#define MX 100005

int dp[MX];
int dps[MX];
int arr[MX];
int tem[MX];
int tes, len;

int rec(int pos)
{
    if(pos >= len) return 0;
    int & res = dp[pos];
    if(tes == dps[pos]) return res;
    dps[pos] = tes;
    res = max(rec(pos+1),rec(pos+2)+arr[pos]);
    return res;
}

int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n) == 2)
    {
        if(n == 0 && m == 0) return 0;
        len = n;
        for(int i = 0; i < m; i++)
        {
            tes++;
            for(int j = 0; j < n; j++)
                scanf("%d", &arr[j]);
            tem[i] = rec(0);
        }
        for(int i = 0; i < m; i++)
            arr[i] = tem[i];
        len = m;
        tes++;
        printf("%d\n", rec(0));
    }
    return 0;
}
