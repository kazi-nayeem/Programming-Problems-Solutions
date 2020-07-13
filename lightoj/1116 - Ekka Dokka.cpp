#include<cstdio>
using namespace std;

int main()
{
    int ti, te;
    unsigned long long int n, two;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf(" %llu", &n);
        if(n&1)
            printf("Case %d: Impossible\n", te);
        else
        {
            two = 1;
            do
            {
                n /= 2;
                two *= 2;
            }while(n%2 == 0);
            printf("Case %d: %llu %llu\n", te, n, two);
        }
    }
    return 0;
}
