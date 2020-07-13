#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n, total, te = 1, tem;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            total += tem;
        }
        int gcd = __gcd(total,n);
        total /= gcd;
        n /= gcd;
        printf("Case %d:\n");
        if(total >= 0)
        {
            if(n == 1) printf("%d\n", total);
            else if(total < n) printf("%d\n-\n%d\n", total, n);
            else
                printf("")
        }
    }
}
