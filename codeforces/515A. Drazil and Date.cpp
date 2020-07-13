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
    int x, y, dis;
    scanf("%d %d %d", &x, &y, &dis);
    x = abs(x);
    y = abs(y);
    if(x+y > dis || (dis-x-y )%2 == 1)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}
