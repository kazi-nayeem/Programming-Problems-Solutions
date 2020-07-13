#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct data
{
    int a, b;
    bool operator < (const data &p) const
    {
        //if(b != p.b)
           // return b<p.b;
        return a<p.a;
    }
};

struct data2
{
    int b;
    data2(int a)
    {
        b = a;
    }
    bool operator < (const data2 &p) const
    {
        return b>p.b;
    }
};

data arr[50005];
priority_queue<data2> qu;

int main()
{
    int te, ti, n, res, pre;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &arr[i].a, &arr[i].b);
        sort(arr,arr+n);
        while(!qu.empty()) qu.pop();
        res = 1;
        qu.push(data2(arr[0].b));
        for(int i = 1; i < n; i++)
        {
            if(arr[i].a > qu.top().b)
            {
                qu.pop();
            }
            qu.push(data2(arr[i].b));
        }
        printf("Case %d: %d\n", te, qu.size());
    }
    return 0;
}
