#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long

int fron[MX];
int bac[MX];
int res[MX];

int main()
{
    int n;
    scanf("%d", &n);
    int x, y;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        fron[y] = x;
        bac[x] = y;
    }
    for(int i = bac[0], pos = 2; i != 0; i = bac[i], pos+=2)
        res[pos] = i;
    if((n&1) == 0)
    {
        for(int i = fron[0], pos = n-1; i != 0; i = fron[i], pos-=2)
                res[pos] = i;
    }
    else
    {
        int pos;
        for(int i = 0; i < MX; i++)
            if(bac[i] > 0 && fron[i] == 0 && bac[0] != i)
        {
            pos = i;
            break;
        }
        for(int i = pos, pos = 1; i != 0; i = bac[i], pos+=2)
            res[pos] = i;
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", res[i]);
    return 0;
}
