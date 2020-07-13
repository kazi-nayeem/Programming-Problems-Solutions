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

int arr[MX];

int main()
{
    int n, res = -1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    int pos = 1, flag;
    for(int i = 0; i < n;)
    {
        //printf("i = %d\n", i);
        flag = 0;
        for(int j = 1; j <= n; j++)
        {
            if(arr[j] == -1) continue;
            if(arr[j] <= i)
            {
                i++;
                flag = 1;
                arr[j] = -1;
            }
        }
        res += flag;
        flag = 0;
        for(int j = n; j >= 1; j--)
        {
            if(arr[j] == -1) continue;
            if(arr[j] <= i)
            {
                i++;
                flag = 1;
                arr[j] = -1;
            }
        }
        res += flag;
    }
    printf("%d\n", res);
    return 0;
}


