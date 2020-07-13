#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef unsigned long long int llu;

int main()
{
    int te, ti;
    llu n, k, last;
    scanf("%d", &ti);

    for(te = 1;te <= ti; te++)
    {
        scanf("%llu", &n);
        last = (sqrt(1+(8*n))-1);
        k = 0;
        for(llu i = 2, j = 1; i <= last; i++)
        {
            if((n-j)%i == 0) k++;
            j += i;
        }
        printf("Case %d: %llu\n", te, k);
    }
    return 0;
}
