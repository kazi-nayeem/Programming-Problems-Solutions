#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

#define MX 1005
#define MXP 4794
#define ll long long

int arr[MX];

int main()
{
    int r, te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &r);
        for(int i = 0; i < r; i++)
            scanf("%d", &arr[i]);
        sort(arr,arr+r);
        printf("%d\n", arr[r-1]-arr[0]);
    }
    return 0;
}

