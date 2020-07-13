#include<cstdio>
using namespace std;

int arr[1005];
int te, ti, n, m, res, total;

bool func(int k)
{
    int now = m;
    for(int i = 0; i < n; i++)
    {
        if(now == 0 || arr[i] > k) return false;
        now--;
        int sum = arr[i];
        while( i+1 < n && arr[i+1]+sum <= k)
        {
            i++;
            sum += arr[i];
        }
    }
    return true;
}

int binary(void)
{
    int beg = 0, en = total;
    int mid = (en+beg)/2;
    while(beg <= en)
    {
        if(!func(mid))
            beg = mid+1;
        else en = mid-1;
        mid = (en+beg)/2;
    }
    return en;
}

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        res = binary();
        if(!func(res)) res++;
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
