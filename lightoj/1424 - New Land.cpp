#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 2005

int arr[MX];
int pre[MX];
int next[MX];

int func(int n)
{
    for(int i = 0; i < n; i++)
    {
        pre[i] = i;
        while(pre[i]>0 && arr[pre[i]-1] >= arr[i])
        {
            pre[i] = pre[pre[i]-1];
        }
    }
    int res = 0;
    for(int i = n-1; i >= 0; i--)
    {
        next[i] = i;
        while(next[i] < n-1 && arr[next[i]+1] >= arr[i])
        {
            next[i] = next[next[i]+1];
        }
        res = max(res,arr[i]*(next[i]-pre[i]+1));
    }
    return res;
}

char str[20005];

int main()
{
    int te, ti, row, col, res;
    char x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &row, &col);
        gets(str);
        memset(arr,0,sizeof arr);
        res = 0;
        for(int i = 0; i < row; i++)
        {
            gets(str);
            for(int j = 0; j < col; j++)
            {
                x = str[j];
                if(x == '0')
                    arr[j] += 1;
                else
                    arr[j] = 0;
            }
            res = max(res,func(col));
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
