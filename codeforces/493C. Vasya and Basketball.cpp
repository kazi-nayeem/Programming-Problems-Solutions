#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 200005
#define MXP 4794
#define ll long long

int first[MX];
int second[MX];
int n , m = -1;
priority_queue<int> qu;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &first[i]);
        qu.push(-first[i]);
        qu.push(-first[i]-1);
        qu.push(-first[i]+1);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &second[i]);
        qu.push(-second[i]);
        qu.push(-second[i]+1);
        qu.push(-second[i]-1);
    }
    sort(first,first+n+1);
    sort(second,second+m+1);
    int pos = 0, a = -1, mx = -100000000, b , i = 1;
    while(!qu.empty())
    {
        int now = abs(qu.top());
        qu.pop();
        for(; i<=n; i++)
            if(now < first[i])
                break;
        for(; pos<=m; pos++)
            if(now < second[pos])
                break;
        int f = (i-1)*2+(n-i+1)*3;
        int s = (pos-1)*2+(m-pos+1)*3;
        //printf("%d %d %d  %d %d\n", now, i, pos, f, s);
        if(f - s > mx || (f-s == mx && a < f))
        {
            a = f;
            b = s;
            mx = f - s;
        }
    }
    printf("%d:%d\n", a, b);
    return 0;
}
