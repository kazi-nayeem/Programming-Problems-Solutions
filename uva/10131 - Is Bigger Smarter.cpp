#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct data
{
    int w, s, in;
    data() {}
    bool operator < (const data & p) const
    {
        if(p.w != w) return w<p.w;
        return p.s<s;
    }
};

data arr[1005];
int inde[1005];
int seq[1005];

void LIS(int n);

int main()
{
    int n = 0;
    while(scanf("%d%d", &arr[n].w, &arr[n].s) == 2)
    {
        arr[n].in = n+1;
        n++;
    }
    LIS(n);
    return 0;
}

void LIS(int n)
{
    sort(arr, arr+n);
    int mx = -1;
    for(int i = 0; i < n; i++) inde[i] = 1;

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            if((arr[i].w < arr[j].w) && (arr[i].s > arr[j].s) && (inde[i]+1 > inde[j]))
                inde[j] = inde[i]+1;
            if(inde[j] > mx)
                mx = inde[j];
        }
    //for(int i = 0;i < n; i++) printf("%d %d\n", arr[i].in, inde[i]);
    printf("%d\n", mx);
    int len = mx;
    arr[n].w = 1000000;
    for(int i = n - 1, j = n; i >= 0 && mx >= 0; i--)
    {
        if(mx == inde[i] && arr[i].w < arr[j].w)
        {
            //printf("%d %d i = %d\n", mx, inde[i], i);
            seq[mx] = arr[i].in;
            mx--;
            j = i;
        }
    }
    for(int i = 1; i <= len; i++)
        printf("%d\n", seq[i]);
    return;
}
