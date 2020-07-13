#include<cstdio>
#include<cstring>
using namespace std;

int trailing_zero(int n);
int binary(int n);

int main()
{
    int te, n, ti, res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        res = binary(n);
        //printf("%d\n", n);
        if(res != -1)
            printf("Case %d: %d\n", te, res);
        else
            printf("Case %d: impossible\n", te);
    }
    return 0;
}

int binary(int n)
{
    int start = 0, finish = 400000050;
    int mid, tem;
    for(mid = finish>>1; start < finish; mid = (start+finish)>>1)
    {
        tem = trailing_zero(mid);
        if(tem == n) return (mid/5)*5;
        if(tem < n) start = mid+1;
        else finish = mid - 1;
    }
    return -1;
}
int trailing_zero(int n)
{
    int sum = 0;
    for(int j = n;j>4;j/=5)
        sum += j/5;
    return sum;
}
