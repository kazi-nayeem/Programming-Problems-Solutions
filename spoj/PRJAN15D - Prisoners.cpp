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
using namespace std;

#define ll long long

int main()
{
    int te, ti, n, total, x;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            total += x;
        }
        printf("%.10lf\n", (double) total/n);
    }
    return 0;
}


