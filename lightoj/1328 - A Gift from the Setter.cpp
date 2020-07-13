#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[100005];

int main()
{
    int te, ti;
    long long k, c;
    int n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld %d %lld", &k, &c, &n, &arr[0]);
        for(int i = 1; i < n; i++)
            arr[i] = (long long)(k * arr[i-1] + c) % 1000007ll;
        sort(arr,arr+n);
        long long pre = 0, total = 0;
        for(int i = 1; i < n; i++)
        {
            pre = (long long) pre + (arr[i]-arr[i-1])*i;
            total += pre;
        }
        printf("Case %d: %lld\n", te, total);
    }
    return 0;
}
