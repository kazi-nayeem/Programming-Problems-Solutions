#include<cstdio>
#include<cmath>
using namespace std;

#define ull unsigned long long int

int main()
{
    ull n = 0, sq, row, col;

    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%llu", &n);
        sq = (ull) sqrt(n);
        if(sq*sq == n)
        {
            if(sq%2 == 0)
                col = sq, row = 1;
            else
                col = 1, row = sq;
        }
        else if(sq%2==0)
        {
            if(sq*sq+sq+1 >= n)
                row = n - sq*sq, col = sq+1;
            else
                row = sq+1, col = (sq<<1) + 2 - n + sq*sq;
        }
        else
        {
            if(sq*sq+sq+1 >= n)
                row = sq+1, col = n-sq*sq;
            else
                row = (sq<<1) + 2 - n + sq*sq, col = sq+1;
        }
        printf("Case %d: %llu %llu\n", te, col, row);
    }
    return 0;
}
