#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

#define MX 46355
#define MXP 4794
#define ll long long

vector<int> a, b;
int last;

int func(void)
{
    int sz1 = a.size();
    int sz2 = b.size();
    int mx = min(sz1,sz2);
    for(int i = 0; i < mx; i++)
    {
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return 2;
    }
    return last;
}

int main()
{
    ll int n, total = 0, x;
    scanf("%I64d", &n);
    for(ll int i = 0; i < n; i++)
    {
        scanf("%I64d", &x);
        if(x>0)
            a.push_back(x), last = 1;
        else
            b.push_back(abs(x)), last = 2;
        total += x;
    }
    if(total == 0)
    {
        if(func() == 1)
            printf("first\n");
        else
            printf("second\n");
    }
    else if( total > 0)
        printf("first\n");
    else
        printf("second\n");
    return 0;
}
