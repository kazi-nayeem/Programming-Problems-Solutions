#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll h[MX];
ll x[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x[i], &h[i]);
    }
    x[n] = 0x7fffffff;
    int to = 1;
    for(int i = 1; i < n; i++)
    {
        if(x[i]-h[i] > x[i-1])
        {
            to++;
        }
        else if(x[i+1]> h[i]+x[i])
        {
            x[i]+=h[i];
            to++;
        }
    }
    printf("%d\n", to);
    return 0;
}
