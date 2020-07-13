#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MX 1000050
#define ll long long

ll int arr[MX];
ll int value[MX];
ll int sequ[MX];
ll int ins[MX];


ll int lis(ll int n)
{
    ll int mx = -1;
    memset(value,0,sizeof value);
    for(ll int i = 1; i <= n; i++) ins[i] = 200000000000000LL;
    ins[0] = -200000000000000000LL;

    for(ll int i = 0; i < n; i++)
    {
        ll int mid, beg = 0, en = n;
        while(beg<=en)
        {
            mid = (beg+en)/2;
            if(ins[mid] < arr[i])
                beg = mid+1;
            else
                en = mid-1;
        }
        //printf("%d\n", beg);
        ins[beg] = arr[i];
        value[i] = beg;
        if(mx<beg)
            mx = beg;
    }
    printf("%lld\n-\n", mx);
    ll int te = mx;
    for(ll int i = n-1; i >= 0 && te > 0; i--)
        if(value[i] == te)
        {
            sequ[te] = arr[i];
            te--;
        }
    for(ll int i = 1; i <= mx; i++)
        printf("%lld\n", sequ[i]);
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll int n = 0;
    while(scanf("%lld", &arr[n++]) == 1);
       // printf("%d\n", arr[n-1]);
    //printf("%d\n", n);
    lis(n);
    return 0;
}
