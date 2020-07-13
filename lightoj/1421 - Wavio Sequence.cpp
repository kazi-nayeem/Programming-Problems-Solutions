#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;

#define MX 100050
#define inf 200000000

int arr[MX];
int inc[MX];
int seq[MX];

int binary(int beg, int en, int num);
void set_infi(int n);

int main()
{
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        set_infi(n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            inc[i] = binary(0,i+4,arr[i]);
        }
        set_infi(n);
        int res = 0;
        for(int i = n; i > 0; i--)
        {
            int pi = binary(0,n-i+5,arr[i]);
            if(pi > inc[i])
                pi = inc[i];
            if(res < pi)
                res = pi;
        }
        printf("Case %d: %d\n", te, (res*2)-1);
    }
    return 0;
}

int binary(int beg, int en, int num)
{
    int high = en, low = beg, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(seq[mid] < num)
            low = mid+1;
        else
            high = mid-1;
    }
    seq[low] = num;
    return low;
}

void set_infi(int n)
{
    for(int i = 1; i <=n+5; i++)
        seq[i] = inf;
    seq[0] = -inf;
}
