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

int main()
{
    int n;
    scanf("%d", &n);
    int pos = 0;
    for(int i = 1, sum = 1; sum <= n; i++)
        {
            pos++, sum+=(i+1)*(i+2)/2;
//            printf("%d\n", sum);
        }
    printf("%d\n", pos);
    return 0;
}
