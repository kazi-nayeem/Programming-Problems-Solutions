#include<cstdio>
using namespace std;

#define MX 100005
#define ll long long int

int arr[MX];

int main()
{
    int te, ti, n, q, t, u, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            res += (ll) arr[i] * (n-2*i-1);
        }
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &t);
            if(t == 1)
                printf("%lld\n", res);
            else
            {
                scanf("%d%d", &u, &v);
                res -= (ll) arr[u]*(n-2*u-1);
                arr[u] = v;
                res += (ll) arr[u]*(n-2*u-1);
            }
        }
    }
    return 0;
}
