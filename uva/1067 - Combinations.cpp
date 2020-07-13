#include<cstdio>
using namespace std;

int main()
{
    int ti, te, n, k;
    long long int total;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &k);
        if(k * 2 > n) k = n - k;
        total = 1;
        for(int i = 1; i <= k; i++, n--)
            total = ((total * n) / i) % 1000003ll;

        printf("Case %d: %lld\n", te, total);
    }
    return 0;
}
