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

int te, ti, a, b, c, n;

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &n);
        if(b+b-a != c)
            printf("Case %d: Error\n", te);
        else
            printf("Case %d: %d\n", te, a+(b-a)*(n-1));
    }
    return 0;
}


