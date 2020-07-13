#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll h[MX];
ll x[MX];
int flag[MX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x[i], &h[i]);
    }
    x[n] = x[n-1]+h[n-1]+10ll;
    flag[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(flag[i-1] == 1)
        {
            if(x[i]-h[i] > x[i-1]) flag[i] = 1;
        }
        else
        {
            if(x[i]-x[i-1] >= h[i]+h[i-1])
            {
                flag[i-1] = flag[i] = 1;
            }
            else if(x[i]-x[i-1] > h[i-1])
                flag[i-1] = 1;
            else if(x[i]-x[i-1] > h[i])
                flag[i] = 1;
        }
    }
    int to = 0;
    for(int i = 0; i < n; i++)
    {
        to+=flag[i];
        //printf("%d ", flag[i]);
    }
    printf("%d\n", to);
    return 0;
}
