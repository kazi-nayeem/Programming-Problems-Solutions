#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define lli long long int

lli arr[302][302];

lli pay(int n, int pos);

int main()
{
    char str[20];
    int n, l1, l2;
    while(gets(str))
    {
        memset(arr, -1, sizeof arr);
        int x = sscanf(str, "%d%d%d", &n, &l1, &l2);
        if(x == 1)
            printf("%lld\n", pay(n,n));
        else if(x == 2)
            printf("%lld\n", pay(n,l1));
        else if(x == 3)
        {
            if(n == 0) printf("%d\n", l2-l1+1);
            else
                printf("%lld\n", pay(n,l2) - pay(n,l1-1));
        }
    }
    return 0;
}

lli pay(int n, int pos)
{
    if(pos <= 0)
    {
        if(n == 0) return 1;
        return 0;
    }
    if(n < 0) return 0;

    lli &res = arr[n][pos];
    if(res != -1) return res;

    lli ret = 0;
    ret = pay(n-pos,pos);
    ret += pay(n,pos-1);

    return res = ret;
}
