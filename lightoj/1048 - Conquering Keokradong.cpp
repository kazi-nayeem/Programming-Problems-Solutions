#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;

struct data
{
    int s, e, tot;
    data() {}
    data(int a, int b, int c)
    {
        s = a;
        e = b;
        tot = c;
    }
};

vector<data> vc;
vector<int> res;

int arr[1005];
int te, ti, n, m, total;

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
void print(int k)
{
    vc.clear();
    int now;
    for(int i = 0; i < n; i++)
    {
        now = i;
        int sum = arr[i];
        while( i+1 < n && arr[i+1]+sum <= k)
        {
            i++;
            sum += arr[i];
        }
        vc.push_back(data(now,i,sum));
    }
    res.clear();
    if(vc.size() < m)
    {
        int i;
        for(i = vc.size()-1; 1+i+res.size() < m;)
        {
            if(vc[i].s == vc[i].e)
            {
                res.push_back(vc[i].tot);
                i--;
            }
            else
            {
                res.push_back(arr[vc[i].e]);
                vc[i].tot -= arr[vc[i].e];
                vc[i].e--;
            }
        }
        for(;i>=0;i--)
            res.push_back(vc[i].tot);
    }
    else
    {
        for(int i = m-1; i >= 0; i--)
            res.push_back(vc[i].tot);
    }
    for(int i = res.size()-1; i >= 0; i--)
        printf("%d\n", res[i]);
    return;
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
        n++;
        m++;
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        int res = binary();
        if(!func(res)) res++;
        printf("Case %d: %d\n", te, res);
        print(res);
    }
    return 0;
}
