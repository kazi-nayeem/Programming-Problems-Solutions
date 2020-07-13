#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MX 1000050

int arr[MX];
int value[MX];
int sequ[MX];
int ins[MX];


int lis(int n)
{
    int mx = -1;
    memset(value,0,sizeof value);
    for(int i = 1; i <= n; i++) ins[i] = 20000000L;
    ins[0] = -20000000L;

    for(int i = n-1; i >= 0; i--)
    {
        int mid, beg = 0, en = n;
        while(beg<=en)
        {
            mid = (beg+en)/2;
            if(ins[mid] < arr[i])
                beg = mid+1;
            else
                en = mid-1;
        }
        ins[beg] = arr[i];
        value[i] = beg;
        if(mx<beg)
            mx = beg;
    }
    return mx;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n = 0, te = 1;
    while(scanf("%d", &arr[0]) == 1)
    {
        if(arr[0] == -1) return 0;
        if(n != 0) putchar('\n');
        n = 1;
        while(scanf("%d", &arr[n]) == 1)
            if(arr[n++] == -1) break;
        printf("Test #%d:\n  maximum possible interceptions: %d\n", te++, lis(n-1));
    }
    return 0;
}

