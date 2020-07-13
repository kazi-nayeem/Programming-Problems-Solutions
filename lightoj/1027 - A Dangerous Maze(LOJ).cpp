#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    int te, ti;
    int n, total, k, x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        total = 0;
        k = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            total += abs(x);
            if(x < 0) k++;
        }
        printf("Case %d: ", te);
        if(k == n)
            printf("inf\n");
        else
            printf("%d/%d\n", total/__gcd(total,n-k), (n-k)/__gcd(total,n-k));
    }
    return 0;
}
