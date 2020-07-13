#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll arr[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", &arr[i]);
    sort(arr,arr+n);
    ll total = 0;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(total <= arr[i])
        {
            total += arr[i];
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
