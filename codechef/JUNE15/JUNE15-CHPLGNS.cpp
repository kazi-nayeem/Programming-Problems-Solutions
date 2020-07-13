#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;


struct point
{
    ll x;
    int y;
    bool operator < (const point & p) const
    {
        return x<p.x;
    }
};

point arr[MX];
int res[MX];

int main()
{
    int te, n, m;
    scanf("%d", &te);
    point tem, first, save;

    while(te--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            arr[i].y = i;
            arr[i].x = 0ll;

            scanf("%d", &m);
            scanf("%lld%lld", &tem.x, &tem.y);
            save = first = tem;
            for(int j = 1; j < m; j++)
            {
                scanf("%lld%lld", &tem.x, &tem.y);
                arr[i].x += tem.y*save.x-tem.x*save.y;
                save = tem;
            }
            tem = first;
            arr[i].x += tem.y*save.x-tem.x*save.y;
            arr[i].x = abs(arr[i].x);
            //printf("%lld\n", arr[i].x);
        }
        sort(arr,arr+n);
        for(int i = 0; i < n; i++)
            res[arr[i].y] = i;
        printf("%d", res[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", res[i]);
        puts("");
    }
    return 0;
}
