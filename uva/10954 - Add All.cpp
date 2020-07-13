#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

#define ll long long int

struct data{
    ll cost, num;
    data(){}
    data(ll a, ll b)
    {
        cost = a;
        num = b;
    }
    bool operator < (const data & p) const
    {
        return p.num < num;
    }
};

priority_queue <data> qu;

int main()
{
    int n, t, cost;
    data tem1, tem2;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        while(!qu.empty()) qu.pop();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            qu.push(data((ll)0,(ll)t));
        }
        for(int i = 1; i < n; i++)
        {
            tem1 = qu.top();
            qu.pop();
            tem2 = qu.top();
            qu.pop();
            qu.push(data(tem1.cost+tem2.cost+tem1.num+tem2.num,tem1.num+tem2.num));
        }
        printf("%lld\n", qu.top().cost);
    }
    return 0;
}
