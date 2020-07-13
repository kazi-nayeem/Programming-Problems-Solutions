//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

#define MX 1005
#define inf 0x3f3f3f3f

typedef int ll;
typedef unsigned long long ull;

int arr[MX];
int row[MX];
int col[MX];

ll func(int n, int mk)
{
    ll res = inf;
    ll cost = 0;
    ll total = 0;
    int pre;
    for(int i = 0; i < n; i++)
    {
        cost = 0;
        total = 0;
        for(int j = 1; j <= n; j++)
        {
            pre = i+j;
            if(pre > n) pre -= n;
            cost += arr[pre]-mk;
            total += abs(cost);
        }
        res = min(res,total);
    }
    return res;
}

char str[MX];

int main()
{
    int te, ti, total, r, c, x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &r, &c);
        memset(row,0,sizeof row);
        memset(col,0,sizeof col);
        total = 0;
        gets(str);
        for(int i = 1; i <= r; i++)
        {
            gets(str);
            for(int j = 1; j <= c; j++)
            {
                if(str[j-1] == '1')
                {
                    total++;
                    row[i]++;
                    col[j]++;
                }
            }
        }
        ll rowres = inf;
        if(total%r == 0)
        {
            memcpy(arr,row,sizeof row);
            rowres = func(r,total/r);
        }

        ll colres = inf;
        if(total%c == 0)
        {
            memcpy(arr,col,sizeof col);
            colres = func(c,total/c);
        }

        //printf("%d %d\n", rowres, colres);
        printf("Case %d: ", te);
        if(rowres != inf && colres != inf)
            printf("both %d\n", rowres+colres);
        else if(rowres != inf)
            printf("row %d\n", rowres);
        else if(colres != inf)
            printf("column %d\n", colres);
        else
            printf("impossible\n");
    }
    return 0;
}
