#include<cstdio>
#include<iostream>
using namespace std;

#define MX 1000501
#define MXA 69590

long long int flag[MX];
long long int arr[MXA];

void fun(void);
void sieve(void);
long long int binary(const long long int fi);

int main()
{
    sieve();
    fun();
    long long int up, low, a, b, ti, te;

    scanf("%lld", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &a, &b);

        low = binary(a);
        up = binary(b);
        if(arr[low] < a)
            low++;
        if(arr[up] > b)
            up--;

        printf("Case %lld: %lld\n", te, up - low + 1);
    }
    for(long long int i = 0; i < 50; i++)
        printf("%lld %lld\n", i, arr[i]);
    for(long long int i = MXA - 50; i < MXA; i++)
        printf("%lld %lld\n", i, arr[i]);
    return 0;

}

long long int binary(const long long int fi)
{
    long long int beg = 0, en = MXA - 1, mid = en/2;
    for(;beg <= en; mid = (beg+en)/2)
    {
        if(arr[mid] == fi) return mid;
        if(arr[mid] > fi)
            en = mid -1;
        else
            beg = mid + 1;
    }
    return mid;
}


void fun(void)
{
    arr[0] = 1;
    for(long long int i = 1; i < MXA; i++)
        arr[i] = arr[i-1] + flag[arr[i-1]];
    return;
}

void sieve(void)
{
    long long int i, j, k, n = MX / 2;
    for(i = 0; i < MX; i++)
        flag[i] = 1;

    for(i = 2; i <= n; i++)
    {
        for(j = i; j < MX; j += i)
            flag[j]++;
    }

    return;
}
