#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MX 30050
#define ll long long int

int arr[MX];
int pre[MX];
int suf[MX];

int main()
{
    int te, ti, n;
    ll mx, tm;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        arr[0] = -1090;
        arr[n+1] = -1923;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            pre[i] = i;
            while(arr[pre[i]-1] >= arr[i])
                pre[i] = pre[pre[i]-1];
            //printf("%d ", pre[i]);
        }
        // puts("");
        for(int i = n; i > 0; i--)
        {
            suf[i] = i;
            while(arr[suf[i]+1] >= arr[i])
                suf[i] = suf[suf[i]+1];
        }
        mx = 0;
        for(int i = 1; i <= n; i++)
        {
            tm = (ll) arr[i]*(suf[i]-pre[i]+1);
            if(tm>mx) mx = tm;
        }
        printf("Case %d: %lld\n", te, mx);
    }
    return 0;
}
