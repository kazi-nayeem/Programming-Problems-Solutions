#include<cstdio>
using namespace std;

int main()
{
    int ti, te, n, one;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        one = 0;
        while(n)
        {
            one += n & 1;
            n >>= 1;
        }
        if(one & 1)
            printf("Case %d: odd\n", te);
        else
            printf("Case %d: even\n", te);
    }
    return 0;
}
