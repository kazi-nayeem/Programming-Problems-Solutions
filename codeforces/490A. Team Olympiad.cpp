#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 200005
#define MXP 4794
#define ll long long

vector<int> vc[3];

int main()
{
    int n, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        vc[x-1].push_back(i);
    }
    int sz = n;
    for(int i = 0; i < 3; i++)
        sz = min(sz,(int)vc[i].size());
    printf("%d\n", sz);
    for(int i = 0; i < sz; i++)
    {
        printf("%d %d %d\n", vc[0][i],vc[1][i],vc[2][i]);
    }
    return 0;
}
