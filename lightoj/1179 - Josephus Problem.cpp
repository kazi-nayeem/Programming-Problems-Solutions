#include<cstdio>
using namespace std;

int main()
{
    int te, ti, n, k, res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &k);
        res = 1;
        for(int i = 2; i <= n; i++)
        {
            res+= k-1;
            res %= i;
            res++;
        }
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}

