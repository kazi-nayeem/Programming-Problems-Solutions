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

#define MX 200005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

struct data
{
    int pos, r, s;
    bool operator < (const data & p) const
    {
        if(r != p.r) return r>p.r;
        return s>p.s;
    }
};

data arr[MX];
int flag[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].s, &arr[i].r);
        arr[i].pos = i+1;
    }
    sort(arr,arr+n);
    int tem = arr[0].s;
    flag[arr[0].pos] = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i].s > tem)
        {
            tem = arr[i].s;
            flag[arr[i].pos] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
        if(flag[i])
            printf("%d ", i);
    return 0;
}
