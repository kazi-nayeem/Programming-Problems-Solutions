#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int factorCount(int n, int t);

int main()
{
    int te, ti, n, r, p, q, two, five, t, f, tm;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &n, &r, &p, &q);
        two = factorCount(n,2);
        five = factorCount(n,5);
        two -= factorCount(r,2);
        five -= factorCount(r,5);
        two -= factorCount(n-r,2);
        five -= factorCount(n-r,5);
        //printf("%d %d\n", two, five);
        t = 0, f = 0, tm = p;
        while(tm % 2 == 0) tm/=2, t++;
        while(tm % 5 == 0) tm/=5, f++;
        two += t*q;
        five += f*q;
        printf("Case %d: %d\n", te, min(two,five));
    }
    return 0;
}

int factorCount(int n, int t)
{
    int sum = 0;
    for(int i = t; n >= i; i*=t)
        sum += n/i;
    return sum;
}
